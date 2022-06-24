#!/bin/bash

sudo chrt -f $1 ./myprog A 100000000 10 0.0 &
sudo chrt -f $2 ./myprog B 100000000 10 0.0 &
sudo chrt -f $3 ./myprog C 100000000 10 0.0 &
