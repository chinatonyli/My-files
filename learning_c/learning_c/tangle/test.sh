#!/bin/bash

NUM=10000

echo "Python"
time ./tang.py $NUM

echo "C Lang"
time ./a.out $NUM

echo "Go Lang"
time ./triangle $NUM
