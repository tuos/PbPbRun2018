current_date_time="`date +%m/%d/%Y-%H:%M`"
echo -n $current_date_time"   "

inFile='output_getaodfromdas_size.txt'
sum=0
while read num; do 
for word in $num; do 
((sum += word))
done
done < "$inFile"
echo $sum

