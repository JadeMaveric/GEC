#!/bin/python
import pandas as pd
import sys


def predict(hypothesis, example):
    """Predicts the outcome of the hypothesis (True/False)"""
    for h,a in zip(hypothesis, example):
        if h == '0':
            return False
        elif h != '?' and h != a:
            return False
    return True


def consistent(hypothesis, example):
    """Returns True if the hypothesis conforms to the example"""
    outcome = predict(hypothesis, example)
    return outcome == example[-1]


def prune(H, example):
    _H = H.copy()
    for h in _H:
        if not consistent(h, example):
            H.remove(h)
    return H


def generate_opposite(hypothesis, example, attributes):
    generated = []
    for i,(h,a) in enumerate(zip(hypothesis, example)):
        if h == '?':
            for option in attributes[i]:
                if option == a:
                    continue
                temp = hypothesis[:i] + tuple([option]) + hypothesis[i+1:]
                generated.append(temp)
    return generated


def generalise(hypothesis, example):
    generalised = []
    for h,a in zip(hypothesis, example):
        if h != a and h == '0':
            generalised.append(a)
        elif h != a:
            generalised.append('?')
        else:
            generalised.append(a)
    return tuple(generalised)


def specialise(record, attribute, hypothesis):
    specialised = []
    for actual, hypothesis in zip(example, S):
        if hypothesis != actual and hypothesis == '0':
            specialised.append(actual)
        elif hypothesis != actual:
            specialised.append('?')
        else:
            specialised.append(actual)
    return specialised


def combine(S, G):
    # Find mismatched attributes
    mismatch = []
    for i,(s,g) in enumerate(zip(S,G)):
        if g == '?' and s != '?':
            mismatch.append((i,s))
    
    combined_hypothesis = []
    G = list(G)
    # Find ways to combine mismatch (binary counting)
    for i in range(len(mismatch)):
        binary = bin(i+1)[2:]
        position = list(reversed(binary))
        position = [i for i,x in enumerate(position) if x == '1']

        temp = G.copy()
        for j in position:
            attr_idx = mismatch[j][0]
            temp[attr_idx] = mismatch[j][1]
        combined_hypothesis.append(tuple(temp))

    return combined_hypothesis


def set_print(H, name):
    print(f"{name}: ", end='')
    if len(H) == 0:
        print("{}")
    elif len(H) == 1:
        print(H)
    else:
        print('{')
        for h in H:
            print('\t', h)
        print('}')

# Main
if len(sys.argv) > 1:
    dataname = sys.argv[1]
else:
    dataname = 'data.csv'

if len(sys.argv) > 2:
    debug = not sys.argv[2] == 'noDebug'
else:
    debug = True


df = pd.read_csv(dataname, sep='\s+')
num_features = len(df.columns) - 1
target = df.columns[-1]
df[target].replace('Yes', True, inplace=True)
df[target].replace('No', False, inplace=True)

# Check if the data is properly formatted
if df[target].dtype != bool:
    raise ValueError("Target attribute must contain boolean values")

S = set([('0',)*num_features])
G = set([('?',)*num_features])

if debug:
    set_print(S, 'S')
    set_print(G, 'G')
        
attributes = [set(df[column]) for column in df.columns[:-1]]

for i, record in enumerate(df.values):
    if debug:
        print(f'\nRecord: {record}')

    target = record[-1]
    example = record[:-1]

    if target == True:
        G = prune(G, record)
        _S = S.copy()
        for s in _S:
            if not consistent(s, record):
                t = generalise(s, record)
                S.remove(s)
                S.add(t)

    else:
        _S = S.copy()
        for s in _S:
            if not consistent(s, record):
                S.remove(s)
        if len(S) == 0:
            print("Null hypothesis S, inconsistent data")
            exit(1)

        _G = G.copy()
        for g in _G:
            if not consistent(g, record):
                t = generate_opposite(g, record, attributes)
                G = G.union(t)
            for seen_example in df.values[:i+1]:
                G = prune(G, seen_example)
    
    if debug:
        set_print(S, 'S')
        set_print(G, 'G')
    if len(G) == 0:
        print("Null hypothesis G, inconsistent Data!")
        exit(2)

# Generate New Hypothesis
final_hypothesis = set([*S, *G])
for s in S:
    for g in G:
        final_hypothesis = final_hypothesis.union(combine(s, g))

set_print(final_hypothesis, 'Version Space') 
