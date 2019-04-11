#!/bin/bash
echo -ne `dasgoclient --query="file dataset=/HISingleMuon/HIRun2018A-04Apr2019-v1/AOD | grep file.size" | awk 'BEGIN{sum=0} {sum+=$1} END {print sum}' 2>/dev/null`"\t"
echo -ne `dasgoclient --query="file dataset=/HIDoubleMuon/HIRun2018A-04Apr2019-v1/AOD | grep file.size" | awk 'BEGIN{sum=0} {sum+=$1} END {print sum}' 2>/dev/null`"\t"
echo -ne `dasgoclient --query="file dataset=/HIDoubleMuonPsiPeri/HIRun2018A-04Apr2019-v1/AOD | grep file.size" | awk 'BEGIN{sum=0} {sum+=$1} END {print sum}' 2>/dev/null`"\t"
echo -ne `dasgoclient --query="file dataset=/HIHardProbes/HIRun2018A-04Apr2019-v1/AOD | grep file.size" | awk 'BEGIN{sum=0} {sum+=$1} END {print sum}' 2>/dev/null`"\t"
echo -ne `dasgoclient --query="file dataset=/HIHardProbesLower/HIRun2018A-04Apr2019-v1/AOD | grep file.size" | awk 'BEGIN{sum=0} {sum+=$1} END {print sum}' 2>/dev/null`"\t"
echo -ne `dasgoclient --query="file dataset=/HIHardProbesPeripheral/HIRun2018A-04Apr2019-v1/AOD | grep file.size" | awk 'BEGIN{sum=0} {sum+=$1} END {print sum}' 2>/dev/null`"\t"
echo -ne `dasgoclient --query="file dataset=/HIMinimumBias0/HIRun2018A-04Apr2019-v1/AOD | grep file.size" | awk 'BEGIN{sum=0} {sum+=$1} END {print sum}' 2>/dev/null`"\t"
echo ""
