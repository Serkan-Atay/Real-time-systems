#!/bin/bash
chrt -r 40 ./task-starter A 3 5 12 &
chrt -r 40 ./task-starter B 1 8 8 &
chrt -r 40 ./task-starter C 2 10 6 &