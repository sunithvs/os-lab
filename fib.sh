#! /bin/bash

# fibanocci series
# sunith vs
# 20220098
# CS B

first=0
sec=1
echo $first
echo $sec
for (( i=1 ; i<=$1 ; i++ ));
do
    third=$(( $first + $sec ))
    echo $third
    first=$sec
    sec=$third
done

# output
# bash fib.sh 10


0
1
1
2
3
5
8
13
21
34
55
89

