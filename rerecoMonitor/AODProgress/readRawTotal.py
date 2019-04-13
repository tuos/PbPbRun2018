nEventPD = []
inFile = open("output_getRAW.txt", "r")
for nEvents in inFile.read().split():  
    nEventPD.append(float(nEvents))
#print nEventPD[0]
print sum(nEventPD)

