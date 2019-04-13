#!/bin/bash

source /cvmfs/cms.cern.ch/cmsset_default.sh
export SCRAM_ARCH=slc6_amd64_gcc700
export SSL_CERT_DIR=/etc/grid-security/certificates
export X509_USER_PROXY=/home/tuos/x509up_u126986

cd /scratch/tuos/trigger/CMSSW_10_3_0_pre5/src/rerecoMonitor/DataVolume
eval `scramv1 runtime -sh`

dateAndTime=$(date +"%Y%m%d_%H%M%S")

echo "running do.sh"
#fileName_do="output_do_$dateAndTime.txt"
fileName_do="output_vandysize_rereco.txt"
./do.sh >> "$fileName_do"


