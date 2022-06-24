#!/bin/bash
sudo chrt -d -P 1000 0 ./myprog A 475000000 10 0.0 &
sudo chrt -d -P 100 0 ./myprog B 475000000 10 0.0 &
sudo chrt -d -P 10 0 ./myprog C 475000000 10 0.0 &
