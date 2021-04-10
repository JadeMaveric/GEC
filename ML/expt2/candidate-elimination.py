#!/bin/python
import pandas as pd

def consistent(hypothesis, example):
    """Returns true if the hypothesis is consistent with the example"""
    outcome = example[-1]
    matches = True
    for h,a in zip(hypothesis, example):
        if h == '0':
            matches &= False
        elif h == '?':
            matches &= True
        else:
            matches &= (h == a)
        
    return matches == outcome

def prune(H, example):
    for h in H:
        if not consistent(h, example):
            H.remove(h)
    return H

# def generate_opposite(G, example, attributes):
#     raise NotImplementedError

def generalise(S, example):
    genralised = []
    for actual, hypothesis in zip(example, S):
        if hypothesis != actual and hypothesis == '0':
            generalised.append(actual)
        elif hypothesis != actual:
            genralised.append('?')
        else:
            genralised.append(actual)
    return genralised


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

# Main
df = pd.read_csv('data.csv')
num_features = len(df.columns) - 1
target = df.columns[-1]

# Check if the data is properly formatted
if df[target].dtype != bool:
    raise ValueError("Target attribute must contain boolean values")

S = set([('0',)*num_features])
G = set([('?',)*num_features])

attributes = {column: set(df[column]) for column in df.columns[:-1]}

for i, record in enumerate(df.values):
    print(f'Record: {record}')

    target = record[-1]
    example = record[:-1]

    if target == True:
        G = prune(G, example)
        for s in S:
            if not consistent(s, example):
                S.remove(s)
                S.add(generalise(s, example))
                # S = least_general(S)
    else:
        S = prune(S, example)
        for g in G:
            if not consistent(g, example):
                G.remove(g)
                G.add(specialise(g, example))
                # G = most_general(G)
        # S = remove_inconsistent(S, example)
        # G.add(generate_opposite(G, example, atributes))
        # G = remove_inconsistent(G, example)
        
        
