#!/bin/python
import pandas as pd

df = pd.read_csv('data.csv')
num_features = len(df.columns) - 1
target = df.columns[-1]

# Check if the data is properly formatted
if df[target].dtype != bool:
    raise ValueError("Target attribute must contain boolean values")

h = []
h.append(['0']*num_features)

def make_consistent(record, hypothesis):
    if not record[-1]:
        return hypothesis
    
    new_hypo = []
    for attr, hypo in zip(record, hypothesis):
        #print(attr, hypo)
        if attr != '0' and hypo == '0':
            new_hypo.append(attr)
        elif attr == hypo:
            new_hypo.append(hypo)
        else:
            new_hypo.append('?')
        #print(new_hypo)
    return new_hypo

for i, record in enumerate(df.values):
    print(f'h{i}: {h[-1]}')
    print('') 
    print(record)
    new_hypo = make_consistent(record, h[-1])
    h.append(new_hypo)

print(f'Final: {h[-1]}')
