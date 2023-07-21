#! /bin/bash
# factorial of a number program

# sunith vs
# 20220098
# CS B
fac=1
for (( i=1 ; i<=$1 ; i++ ));
do
    fac=$(($fac * $i))
done

echo $fac


# output 
# bash fac.sh 5
# 120
