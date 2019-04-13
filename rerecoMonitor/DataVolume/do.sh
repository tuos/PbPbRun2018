#echo "aod for each pd"
#./getaodfromdas.sh
#echo "get total aod"
#./getaod.sh
#echo "get aod at vandy"
#./getaodvandy.sh

current_date_time="`date +%m/%d/%Y-%H:%M`"
echo -n $current_date_time"   "
./getaodvandy.sh


#echo "get aod taped"
#./getaodtaped.sh
#echo "raw for each pd"
#./getrawfromdas.sh
#echo "get total raw"
#./getraw.sh
#echo "get raw at fnal"
#./getrawfnal.sh
#echo "get raw taped"
#./getrawtaped.sh
