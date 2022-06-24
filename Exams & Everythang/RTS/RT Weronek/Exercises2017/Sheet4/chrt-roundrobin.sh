#!/bin/bash
if [ "$#" -ne 3 ]; then
    echo "Syntax is ./chrt.sh <priority1> <priority2> <priority3>"
    exit 1
fi
sudo chrt -r $1 ./myprog A 475000000 10 0.0 &
sudo chrt -r $2 ./myprog B 475000000 10 0.0 &
sudo chrt -r $3 ./myprog C 475000000 10 0.0 &
