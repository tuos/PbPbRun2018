while read -r line; do
echo $line
./getraw.sh $line > totalraw/$line
done < runs.txt
