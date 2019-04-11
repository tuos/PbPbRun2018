#!/bin/bash
export SSL_CERT_DIR=/etc/grid-security/certificates

dateAndTime=$(date +"%Y%m%d_%H%M%S")

echo "running do.sh"
fileName_do="output_do_$dateAndTime.txt"
./do.sh > "$fileName_do"

