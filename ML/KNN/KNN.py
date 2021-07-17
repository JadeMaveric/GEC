import numpy as np
import pandas as pd

class KNN:
    def __init__(self, distance_metric=None):
        if distance_metric:
            self.distance_metric = distance_metric
        else:
            self.distance_metric = self.euclidean_sq
    

    def fit(self, X, y):
        self.data = pd.DataFrame(X) 
        self.data['target'] = y

    
    def euclidean_sq(self, v1, v2):
        return np.sum([(a - b)**2 for a,b in zip(v1, v2)])

    
    def predict(self, X, k=3, task='logistic'):
        self.data['distance'] = self.data.apply(lambda v1: self.distance_metric(v1, X), axis=1)
        sorted_df = self.data.sort_values('distance').iloc[:k]
        if task == 'logistic':
            predicted = sorted_df['target'].value_counts().index[0]
        elif task == 'linear':
            predicted = sorted_df['target'].sum() / sorted_df['target'].count()
        return predicted

    
    def evaluate(self, X, y, k=3):
        predicted = np.array([self.predict(x, k) for x in X])
        return np.sum(predicted == y) / len(y)


class WeightedKNN (KNN):
    def __init__(self, distance_metric=None):
        if distance_metric:
            self.distance_metric = distance_metric
        else:
            self.distance_metric = self.euclidean
    

    def euclidean(self, v1, v2):
        return np.sqrt(self.euclidean_sq(v1, v2))


    def predict(self, X, k=3, task='logistic'):
        self.data['distance'] = self.data.apply(lambda v1: self.distance_metric(v1, X), axis=1)
        self.data['weight'] = 1 / self.data['distance']
        sorted_df = self.data.sort_values('distance').iloc[:k]
        if task == 'logistic':
            candidates = {
                label: sorted_df[sorted_df.target == label]['weight'].sum() / sorted_df['weight'].sum()
                for label in sorted_df['target'].unique()
            }
            predicted = sorted(candidates, key = lambda l: candidates[l], reverse=True)[0]
        elif task == 'linear':
            values = sorted_df['target']
            weights = sorted_df['weight']
            predicted = sum([v*w for v,w in zip(values, weights)])
        return predicted
