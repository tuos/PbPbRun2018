echo -ne `{ dasgoclient --query="run dataset=/HISingleMuon/HIRun2018A-PromptReco-v1/AOD " ; dasgoclient --query="run dataset=/HISingleMuon/HIRun2018A-PromptReco-v2/AOD " ;} | sort -n | uniq | wc -l`"\t"
echo -ne `{ dasgoclient --query="run dataset=/HIDoubleMuon/HIRun2018A-PromptReco-v1/AOD " ; dasgoclient --query="run dataset=/HIDoubleMuon/HIRun2018A-PromptReco-v2/AOD " ;} | sort -n | uniq | wc -l`"\t"
echo -ne `{ dasgoclient --query="run dataset=/HIForward/HIRun2018A-PromptReco-v1/AOD " ; dasgoclient --query="run dataset=/HIForward/HIRun2018A-PromptReco-v2/AOD " ;} | sort -n | uniq | wc -l`"\t"
echo -ne `{ dasgoclient --query="run dataset=/HIHardProbes/HIRun2018A-PromptReco-v1/AOD " ; dasgoclient --query="run dataset=/HIHardProbes/HIRun2018A-PromptReco-v2/AOD " ;} | sort -n | uniq | wc -l`"\t"
echo -ne `{ dasgoclient --query="run dataset=/HIHardProbesLower/HIRun2018A-PromptReco-v1/AOD " ; dasgoclient --query="run dataset=/HIHardProbesLower/HIRun2018A-PromptReco-v2/AOD " ;} | sort -n | uniq | wc -l`"\t"
echo -ne `{ dasgoclient --query="run dataset=/HIHardProbesPeripheral/HIRun2018A-PromptReco-v1/AOD " ; dasgoclient --query="run dataset=/HIHardProbesPeripheral/HIRun2018A-PromptReco-v2/AOD " ;} | sort -n | uniq | wc -l`"\t"
echo -ne `{ dasgoclient --query="run dataset=/HIHeavyFlavor/HIRun2018A-PromptReco-v1/AOD " ; dasgoclient --query="run dataset=/HIHeavyFlavor/HIRun2018A-PromptReco-v2/AOD " ;} | sort -n | uniq | wc -l`"\t"
echo -ne `{ dasgoclient --query="run dataset=/HIMinimumBias0/HIRun2018A-PromptReco-v1/AOD " ; dasgoclient --query="run dataset=/HIMinimumBias0/HIRun2018A-PromptReco-v2/AOD " ;} | sort -n | uniq | wc -l`"\t"
echo -ne `{ dasgoclient --query="run dataset=/HIMinimumBiasReducedFormat0/HIRun2018A-PromptReco-v1/AOD " ; dasgoclient --query="run dataset=/HIMinimumBiasReducedFormat0/HIRun2018A-PromptReco-v2/AOD " ;} | sort -n | uniq | wc -l`"\t"
echo ""
