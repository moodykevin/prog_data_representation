#!/bin/bash

echo "enter the exponent for counter.cpp:"
read exponent
total=0

for ((i=1;i <= 5; i++))
do
    echo "Running iteration ${i}..."
    TIME=`./a.out ${exponent}`
    echo "time taken: ${TIME} ms"
    total=`expr $total + $TIME`
done

echo "5 iterations took $total ms"

AVGTIME=$(($total/5))
echo "Average time was $AVGTIME ms"
