#!/bin/bash

operations=$(./benchmark)
#echo "Benchmark measured $operations FLOPS"

chrt -r 50 ./task-starter A $[operations*3] 5 6 &
chrt -r 50 ./task-starter B $[operations*2] 8 5 &
chrt -r 50 ./task-starter C $[operations*1] 10 5 &