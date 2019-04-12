#!/bin/bash

source /cvmfs/cms.cern.ch/cmsset_default.sh
export SCRAM_ARCH=slc6_amd64_gcc491
cd /home/tuos/CMSSW_7_5_5_patch3/src
eval `scramv1 runtime -sh`
cd /scratch/tuos/trigger/rerecoMonitor/Visualization
python makePlot.py

