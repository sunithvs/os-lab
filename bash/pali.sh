#!/bin/bash

num=$1

tmp=$num
rev=0
while [ $num -gt 0 ]; do
    rem=$(($num % 10))
    num=$(($num/10))
    rev=$(($rev * 10 +$rem))
done

if [ $rev -eq $tmp ]; then
    echo "The number is palindrome"
fi
