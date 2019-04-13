#!/usr/bin/env python
# -*- coding: utf-8 -*-

import urllib2
import re
import sre
import datetime
import time


url = "https://autocms.accre.vanderbilt.edu/depotmon/index.html"
req = urllib2.Request(url, headers={'User-Agent' : "Magic Browser"})
contents = urllib2.urlopen(req).read()
#unicode_contents = contents.decode('gbk', 'ignore')
unicode_contents = contents.decode('utf-8').encode('utf-8')
patternA='USED and '
patternB=' TB FREE'
pattern=patternA + "(.*)" + patternB
matches = sre.findall(pattern, unicode_contents)

now = datetime.datetime.now()
dateDay=now.strftime("%m/%d/%Y-%H:%M")
fileOutName="output_vandysize_usable.txt"
fileOutput = open(fileOutName, "a")
fileOutput.write(time.strftime("%m/%d/%Y-%H:%M"))

#print matches
#   outStrPre='show1image("' + matches[i][3] + '", "' + matches[i][0] + '", "width:100%", "热门", "' + matches[i][1] + '", "");'

fileOutput.write("   "+matches[0]+"   "+str(float(matches[0])*2.0/3.0*0.85)+"\n")
fileOutput.close()



