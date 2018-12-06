#!/bin/bash

source /cvmfs/cms.cern.ch/cmsset_default.sh
export SCRAM_ARCH=slc6_amd64_gcc700
export SSL_CERT_DIR=/etc/grid-security/certificates
export X509_USER_PROXY=/home/tuos/x509up_u126986

cd /scratch/tuos/trigger/CMSSW_10_3_0_pre5/src/lihan/AODProgress
eval `scramv1 runtime -sh`


dateAndTime=$(date +"%Y%m%d_%H%M%S")

echo "running getrawfromdas.sh"
fileName_getrawfromdas="output_getrawfromdas_$dateAndTime.txt"
./getrawfromdas.sh > "$fileName_getrawfromdas"

echo "running getaodfromdas.sh"
fileName_getaodfromdas="output_getaodfromdas_$dateAndTime.txt"
./getaodfromdas.sh > "$fileName_getaodfromdas"

