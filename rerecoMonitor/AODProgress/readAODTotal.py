nEventPD = []
inFile = open("output_getaodfromdas_20190412_122826.txt", "r")
for nEvents in inFile.read().split():  
    nEventPD.append(float(nEvents))
#print nEventPD[0]
print sum(nEventPD)

