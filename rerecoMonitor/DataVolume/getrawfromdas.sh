echo -ne `dasgoclient --query="file dataset=/HISingleMuon/HIRun2018A-v1/RAW | grep file.size" | awk 'BEGIN{sum=0} {sum+=$1} END {print sum}' 2>/dev/null`"\t"
echo -ne `dasgoclient --query="file dataset=/HIDoubleMuon/HIRun2018A-v1/RAW | grep file.size" | awk 'BEGIN{sum=0} {sum+=$1} END {print sum}' 2>/dev/null`"\t"
echo -ne `dasgoclient --query="file dataset=/HIForward/HIRun2018A-v1/RAW | grep file.size" | awk 'BEGIN{sum=0} {sum+=$1} END {print sum}' 2>/dev/null`"\t"
echo -ne `dasgoclient --query="file dataset=/HIHardProbes/HIRun2018A-v1/RAW | grep file.size" | awk 'BEGIN{sum=0} {sum+=$1} END {print sum}' 2>/dev/null`"\t"
echo -ne `dasgoclient --query="file dataset=/HIHardProbesLower/HIRun2018A-v1/RAW | grep file.size" | awk 'BEGIN{sum=0} {sum+=$1} END {print sum}' 2>/dev/null`"\t"
echo -ne `dasgoclient --query="file dataset=/HIHardProbesPeripheral/HIRun2018A-v1/RAW | grep file.size" | awk 'BEGIN{sum=0} {sum+=$1} END {print sum}' 2>/dev/null`"\t"
echo -ne `dasgoclient --query="file dataset=/HIHeavyFlavor/HIRun2018A-v1/RAW | grep file.size" | awk 'BEGIN{sum=0} {sum+=$1} END {print sum}' 2>/dev/null`"\t"
declare -i mbtotal=0
declare -i mbr=0
mbtotal=`dasgoclient --query="file dataset=/HIMinimumBias*/HIRun2018A-v1/RAW | grep file.size" | awk 'BEGIN{sum=0} {sum+=$1} END {print sum}' 2>/dev/null`
mbr=`dasgoclient --query="file dataset=/HIMinimumBiasReducedFormat*/HIRun2018A-v1/RAW | grep file.size" | awk 'BEGIN{sum=0} {sum+=$1} END {print sum}' 2>/dev/null`
declare -i mb=0
mb=$(($mbtotal-$mbr))
echo -ne "$mb""\t"
echo -ne "$mbr""\t"
echo ""
