import datetime
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.dates as mdates

days, volumeSize = np.loadtxt("../DataVolume/output_vandysize_rereco.txt", unpack=True,
        converters={ 0: mdates.strpdate2num('%m/%d/%Y-%H:%M')})

fig = plt.figure(figsize=(15,10))
volumeSize=volumeSize*(1e-12)
plt.plot_date(x=days, y=volumeSize, fmt="r", marker='o', markersize=20, linestyle='-', color='r', linewidth=5.0, label='Re-reco AOD volume @Vandy')
plt.legend(loc='upper left', numpoints = 1, fontsize=40)
plt.title("Re-reco AOD volume (Vandy) in TB vs. Time, figure made @ "+str(datetime.datetime.now().strftime("%Y-%m-%d %H:%M"))+" CST", fontsize=20)
plt.ylabel("PbPb 2019 re-reco AOD Volume (TB)", fontsize=25)
ax = fig.add_subplot(111)
ax.tick_params(axis='x', labelsize=25)
ax.tick_params(axis='y', labelsize=25)
plt.grid(True)
plt.ylim(0, 500)
fig.autofmt_xdate()
plt.xlim([datetime.date(2019, 4, 9), datetime.date(2019, 4, 16)])
fig.savefig('rerecoVandyVolume.png')

# fig for vandy usable size
days2, totalFreeSize, usableSize = np.loadtxt("../UsableSizeVandy/output_vandysize_usable.txt", unpack=True,
        converters={ 0: mdates.strpdate2num('%m/%d/%Y-%H:%M')})

fig = plt.figure(figsize=(15,10))
plt.plot_date(x=days2, y=usableSize, fmt="r", marker='o', markersize=20, linestyle='-', color='r', linewidth=5.0, label='Usable disk space @Vandy')
plt.legend(loc='upper left', numpoints = 1, fontsize=40)
plt.title("Vandy usable volume in TB vs. Time, figure made @ "+str(datetime.datetime.now().strftime("%Y-%m-%d %H:%M"))+" CST", fontsize=20)
plt.ylabel("Vandy usable volume (TB)", fontsize=25)
ax = fig.add_subplot(111)
ax.tick_params(axis='x', labelsize=25)
ax.tick_params(axis='y', labelsize=25)
plt.grid(True)
plt.ylim(0, 1300)
fig.autofmt_xdate()
plt.xlim([datetime.date(2019, 4, 9), datetime.date(2019, 4, 16)])
fig.savefig('vandyUsableVolume.png')

# fig for re-reco progress
days3, nEvents = np.loadtxt("../AODProgress/output_rereco_events.txt", unpack=True,
        converters={ 0: mdates.strpdate2num('%m/%d/%Y-%H:%M')})

fig = plt.figure(figsize=(15,10))
nEvents=nEvents*(1e-6)
plt.plot_date(x=days, y=volumeSize, fmt="r", marker='o', markersize=20, linestyle='-', color='r', linewidth=5.0, label='Processed events (M)')
plt.legend(loc='upper left', numpoints = 1, fontsize=40)
plt.title("Processed events (M) in DAS vs. Time, figure made @ "+str(datetime.datetime.now().strftime("%Y-%m-%d %H:%M"))+" CST", fontsize=20)
plt.ylabel("PbPb 2019 re-reco processed events (M)", fontsize=25)
ax = fig.add_subplot(111)
plt.text(0.69, 0.09, 'Expected events = 489.1 M', ha='center', va='center', transform=ax.transAxes, fontsize=30)
ax.tick_params(axis='x', labelsize=25)
ax.tick_params(axis='y', labelsize=25)
plt.grid(True)
plt.ylim(0, 600)
fig.autofmt_xdate()
plt.xlim([datetime.date(2019, 4, 9), datetime.date(2019, 4, 16)])
fig.savefig('rerecoProgressEvents.png')



