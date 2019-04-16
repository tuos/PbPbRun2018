import re

size = []
with open("allSize.txt") as inFile:
  for line in inFile:
    z = re.match(r'(.*)T ', line)
    if z:
#      print((z.groups()))
#      print z.group()[:-2]
      size.append(float(z.group()[:-2]))

print sum(size)



