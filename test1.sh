#!/bin/bash
read L M
declare -a tree
num=0

for (( i=1; i<=${M}; i++ ));do
    read p q
    for(( j=${p}; j<=${q}; j++ ));do
        tree[${j}]=1
    done
done

for (( l=0; l<=${L}; l++ ));do
    if [[ ${tree[${l}]} -ne 1 ]];then
        num=$[${num} + 1]
    fi
done

echo ${num}
