#!/bin/bash
for ((tetris_size=1;tetris_size<=26;tetris_size++))
do
	for ((tests_per_size=100;tests_per_size>0;tests_per_size--))
	do
		python tetmaker.py $tetris_size
		time ./fillit tet.txt 2>> score.txt
	done
done
