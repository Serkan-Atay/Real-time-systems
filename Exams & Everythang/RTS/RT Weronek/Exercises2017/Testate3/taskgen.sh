#!/bin/bash
sudo /usr/bin/chrt -r 60 taskset 1 ./task1 A 5200000 5 200000000 &
sudo /usr/bin/chrt -r 50 taskset 1 ./task2 B 5200000 7 250000000 &
sudo /usr/bin/chrt -r 40 taskset 1 ./task3 C 5200000 20 300000000 &
