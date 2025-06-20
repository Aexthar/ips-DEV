import numpy as np
import matplotlib.pyplot as plt
import os
import csv
import sys

def plotCsv(path):

    if not(os.path.isfile(path)):
        print("CSV file doesn't exists.")
        return(1)
    
    x = []
    y = []

    with open(path,'r') as csvfile:
        plots = csv.reader(csvfile, delimiter = ',')
    
        for row in plots:
            x.append(row[0])
            y.append(row[1])

    plt.plot(x, y, 'ro')
    plt.xlabel("Position z")
    plt.ylabel("Psi value")
    plt.title("Solution of the 1D-HO")
    plt.show()

if __name__ == "__main__":
    path = sys.argv[1]
    plotCsv(path)
