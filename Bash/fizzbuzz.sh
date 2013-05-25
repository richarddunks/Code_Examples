#!/bin/bash
for i in {1..100}
do
	if [ $(($i%15)) -eq 0 ]
	then
		echo "FIZZBUZZ\n"
	elif [ $(($i%3)) -eq 0 ]
	then
		echo "FIZZ\n"
	elif [ $(($i%5)) -eq 0 ]
	then
		echo "BUZZ\n"
	else
		echo "$i\n"
	fi
done