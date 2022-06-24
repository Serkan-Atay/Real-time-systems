#!/bin/bash

sudo chrt -r $1 ./myprog A 100000000 10 0.0 &
sudo chrt -r $2 ./myprog B 100000000 10 0.0 &
sudo chrt -r $3 ./myprog C 100000000 10 0.0 &
