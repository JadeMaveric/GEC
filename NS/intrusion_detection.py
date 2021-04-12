from scipy import stats
import numpy as np
import pandas as pd
import sys

if len(sys.argv) < 2:
    print("USAGE: python intrusion_detection.py dataset_file [threshold]\nDataset is a newline separated list of numbers\nthreshold is the positive z-score threshold value [default=1]")
    exit(42)

threshold = len(sys.argv) == 3 and x[2] or 1

try:
    data = open(sys.argv[1])
    data = data.read()
    data = data.split('\n')
    data = [float(x) for x in data if x]
    data = np.array(data)
except:
    print("Error: Could not read and format data")

z_data = stats.zscore(data)
abnormal = np.abs(z_data) > threshold

df = pd.DataFrame(zip(data, z_data, abnormal), columns=["Data", "Z-Score", "Abnormal?"])
print(df)

