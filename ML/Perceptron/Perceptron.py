import numpy as np
import pandas as pd


class Perceptron:
    def __init__(self):
        self.data = None
        self.target = ""
        self.attributes = []
        self.weight = np.array([])
        self.bias = 0
        self.threshold = 0.5
        self.learning_rate = 0.1


    # Helper Functions #
    def _perceptron_rule(self, wi, t, o, xi):
        return wi + self.learning_rate * (int(t) - int(o)) * xi


    def _predict(self, row):
        data = np.array(row)
        return (np.sum(self.weight * data) + self.bias) > self.threshold

    # Main Functions #
    def fit(self, data, threshold=0.5, learning_rate=0.1, num_epochs=5, initialise_weights=True, debug=False):
        if data[data.columns[-1]].dtype != bool:
            raise ValueError(f"Target Attribute must be boolean, found {data[data.columns[-1]].dtype}")

        self.data = data
        self.attributes = list(data.columns[:-1])
        self.target = data.columns[-1]
        self.threshold = threshold
        self.learning_rate = learning_rate
        
        if initialise_weights:
            self.weight = np.random.rand(len(self.attributes))
            self.bias = np.random.random()

        if debug:
            columns = [f"x{i+1}" for i in range(len(self.attributes))]
            columns.extend(['true', 'observed', 'bias'])
            columns.extend([f"w{i+1}" for i in range(len(self.attributes))])
            row = ['-' for i in range(len(self.attributes))]
            row.extend(['-', '-', self.bias])
            row.extend(list(self.weight))
            log = pd.DataFrame([row], columns=columns, index=[0])
        
        for epoch in range(num_epochs):
            for row in data.iloc:
                x = np.array(row[:-1])
                t = row[-1]
                o = self._predict(x)
                
                for i in range(len(self.attributes)):
                    self.weight[i] = self._perceptron_rule(self.weight[i], t, o, x[i])
                self.bias = self._perceptron_rule(self.bias, t, o, 1)
                
                if debug:
                    row = list(x)
                    row.extend([t,o,self.bias])
                    row.extend(list(self.weight))
                    log = log.append(pd.DataFrame([row], columns=log.columns, index=[epoch+1]))

        if debug:
            print(log)


    def predict(self, data):
        if len(data.columns) != len(self.attributes):
            raise ValueError(f"Expected {len(self.attributes)} attributes, received {len(data.columns)}")

        return data.apply(_predict, axis=1)

