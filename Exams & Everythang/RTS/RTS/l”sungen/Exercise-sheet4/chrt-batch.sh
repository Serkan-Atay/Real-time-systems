#!/bin/bash
sudo chrt -b 0 ./myprog A 475000000 10 0.0 &
sudo chrt -b 0 ./myprog B 475000000 10 0.0 &
sudo chrt -b 0 ./myprog C 475000000 10 0.0 &
