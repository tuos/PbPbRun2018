echo -ne `{ dasgoclient --query="file dataset=/HISingleMuon/HIRun2018A-PromptReco-v1/AOD | grep file.size" ; dasgoclient --query="file dataset=/HISingleMuon/HIRun2018A-PromptReco-v2/AOD | grep file.size" ;} | awk 'BEGIN{sum=0} {sum+=$1} END {print sum}'`"\t"
echo -ne `{ dasgoclient --query="file dataset=/HIDoubleMuon/HIRun2018A-PromptReco-v1/AOD | grep file.size" ; dasgoclient --query="file dataset=/HIDoubleMuon/HIRun2018A-PromptReco-v2/AOD | grep file.size" ;} | awk 'BEGIN{sum=0} {sum+=$1} END {print sum}'`"\t"
echo -ne `{ dasgoclient --query="file dataset=/HIForward/HIRun2018A-PromptReco-v1/AOD | grep file.size" ; dasgoclient --query="file dataset=/HIForward/HIRun2018A-PromptReco-v2/AOD | grep file.size" ;} | awk 'BEGIN{sum=0} {sum+=$1} END {print sum}'`"\t"
echo -ne `{ dasgoclient --query="file dataset=/HIHardProbes/HIRun2018A-PromptReco-v1/AOD | grep file.size" ; dasgoclient --query="file dataset=/HIHardProbes/HIRun2018A-PromptReco-v2/AOD | grep file.size" ;} | awk 'BEGIN{sum=0} {sum+=$1} END {print sum}'`"\t"
echo -ne `{ dasgoclient --query="file dataset=/HIHardProbesLower/HIRun2018A-PromptReco-v1/AOD | grep file.size" ; dasgoclient --query="file dataset=/HIHardProbesLower/HIRun2018A-PromptReco-v2/AOD | grep file.size" ;} | awk 'BEGIN{sum=0} {sum+=$1} END {print sum}'`"\t"
echo -ne `{ dasgoclient --query="file dataset=/HIHardProbesPeripheral/HIRun2018A-PromptReco-v1/AOD | grep file.size" ; dasgoclient --query="file dataset=/HIHardProbesPeripheral/HIRun2018A-PromptReco-v2/AOD | grep file.size" ;} | awk 'BEGIN{sum=0} {sum+=$1} END {print sum}'`"\t"
echo -ne `{ dasgoclient --query="file dataset=/HIHeavyFlavor/HIRun2018A-PromptReco-v1/AOD | grep file.size" ; dasgoclient --query="file dataset=/HIHeavyFlavor/HIRun2018A-PromptReco-v2/AOD | grep file.size" ;} | awk 'BEGIN{sum=0} {sum+=$1} END {print sum}'`"\t"
declare -i mbtotal=0
declare -i mbr=0
mbtotal=`{ dasgoclient --query="file dataset=/HIMinimumBias*/HIRun2018A-PromptReco-v1/AOD | grep file.size" ; dasgoclient --query="file dataset=/HIMinimumBias*/HIRun2018A-PromptReco-v2/AOD | grep file.size" ;} | awk 'BEGIN{sum=0} {sum+=$1} END {print sum}'`
mbr=`{ dasgoclient --query="file dataset=/HIMinimumBiasReducedFormat*/HIRun2018A-PromptReco-v1/AOD | grep file.size" ; dasgoclient --query="file dataset=/HIMinimumBiasReducedFormat*/HIRun2018A-PromptReco-v2/AOD | grep file.size" ;}| awk 'BEGIN{sum=0} {sum+=$1} END {print sum}'`
declare -i mb=0
mb=$(($mbtotal-$mbr))
echo -ne "$mb""\t"
echo -ne "$mbr""\t"
echo ""
