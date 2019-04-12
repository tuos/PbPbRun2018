import datetime
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.dates as mdates

days, volumeSize = np.loadtxt("../DataVolume/output_vandysize_rereco.txt", unpack=True,
        converters={ 0: mdates.strpdate2num('%m/%d/%Y-%H:%M')})

fig = plt.figure(figsize=(15,10))
volumeSize=volumeSize*(1e-12)
plt.plot_date(x=days, y=volumeSize, fmt="r", marker='o', markersize=20, linestyle='-', color='r', linewidth=5.0, label='Volume @Vandy vs. Time')
plt.legend(loc='upper left', numpoints = 1, fontsize=40)
plt.title("Volume (Vandy) in TB vs. Time, figure made @ "+str(datetime.datetime.now().strftime("%Y-%m-%d %H:%M"))+" CST", fontsize=20)
plt.ylabel("PbPb 2019 re-reco AOD Volume (TB)", fontsize=25)
#plt.xlabel("", fontsize=20)
ax = fig.add_subplot(111)
#plt.text(0.5, 0.2, 'Total Volume in RAW data = 1450.06 TB', ha='center', va='center', transform=ax.transAxes, fontsize=30)
ax.tick_params(axis='x', labelsize=25)
ax.tick_params(axis='y', labelsize=25)
plt.grid(True)
plt.ylim(0, 500)
fig.autofmt_xdate()
#plt.xlim([datetime.date(2015, 12, 24), datetime.datetime.now() + datetime.timedelta(days=1)])
plt.xlim([datetime.date(2019, 4, 9), datetime.date(2019, 4, 16)])
fig.savefig('vandyVolume.png')

