#!/bin/bash
export SSL_CERT_DIR=/etc/grid-security/certificates

dateAndTime=$(date +"%Y%m%d_%H%M%S")

echo "running getrawfromdas.sh"
fileName_getrawfromdas="output_getrawfromdas_$dateAndTime.txt"
./getrawfromdas.sh > "$fileName_getrawfromdas"

echo "running getaodfromdas.sh"
fileName_getaodfromdas="output_getaodfromdas_$dateAndTime.txt"
./getaodfromdas.sh > "$fileName_getaodfromdas"

