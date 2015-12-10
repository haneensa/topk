# CS245 - Databases
# Programming project 2
# Fall 2015
# Generate data file for Fagin's and TA algorithm

import random

############################
# Parameters

maxLines = 50000000
maxCollumns = 20
fileName = "data-c20.txt"
############################

print "File =", fileName, "   Rows =", maxLines, "   Collumns =", maxCollumns

random.seed(0)

with open(fileName, 'w') as fOut:
    for i in range(1, maxLines+1):
        if i%100000 == 0:
            print i
        s = str(i)
        for j in range(maxCollumns):
            s = s + ", " + str(random.randint(0, 50000000))
        s = s + '\n'
        fOut.write(s)




