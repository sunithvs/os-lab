#! /bin/bash
# sum of n number
# sunith vs
# 20220098
# CS B
sum_n=0
for (( i=1 ; i<=$1 ; i++ ));
do
    sum_n=$(($sum_n + $i))
done

echo $sum_n
# bash sum_n.sh  10

# 55
