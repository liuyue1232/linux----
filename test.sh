#!/bin/bash
read var

Start=2
End=10000
declare -a Prime

function init_prime(){
    local end=10000
    local i
    Prime[1]=1
    for((i=2;i<=${end};i++));do
        if [[ Prime[$[i]] -eq 1 ]]; then
            continue
        fi
        Prime[0]=$[ ${Prime[0]} + 1 ]
        Prime[${Prime[0]}]=$i
        for((j=$[${i} * ${i}];j<=${end};j+=i));do
            Prime[${j}]=1
        done
    done
}
init_prime 10000

echo ${Prime[${var}]}
