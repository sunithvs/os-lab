#!/bin/bash

first=1
second=1

while [ $second -le $1 ]; do
  third=$(($first+$second))
  first=$second
  second=$third
  index=$(($first+1))
  while [ $index -lt $second ]; do
      echo $index
      index=$(($index+1))
  done 
done
