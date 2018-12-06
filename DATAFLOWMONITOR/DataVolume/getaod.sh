declare -i sum=0;
while read -r line; do
#echo $line
num=`dasgoclient -query="file dataset=$line | grep file.size" 2>/dev/null | awk 'BEGIN{val=0} {val+=$1} END{print val}'`
sum=$(($sum+$num))
done < dataset/aoddataset.txt
echo $sum
