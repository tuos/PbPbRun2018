echo "------ produced AOD size ------"
cd /scratch/tuos/trigger/CMSSW_10_3_0_pre5/src/rerecoMonitor/DataVolume
bash ./datavolumeJob.sh

echo "------ processed number of events ------"
cd /scratch/tuos/trigger/CMSSW_10_3_0_pre5/src/rerecoMonitor/AODProgress
bash ./progressJob.sh

echo "------ usable disk space at Vanderbilt T2 ------"
cd /scratch/tuos/trigger/CMSSW_10_3_0_pre5/src/rerecoMonitor/UsableSizeVandy
python ./sizeVandy.py

echo "------ making plots ------"
cd /scratch/tuos/trigger/CMSSW_10_3_0_pre5/src/rerecoMonitor/Visualization
bash ./plotjobs.sh

echo "------ cp plots to web ------"
cd /scratch/tuos/trigger/CMSSW_10_3_0_pre5/src/rerecoMonitor/Visualization
cp *.png ~/web/rereco2019/


