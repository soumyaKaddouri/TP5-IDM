#!/bin/bash

for i in {0..9}
do
    ./question5 "status$i.txt" > "EstimationPI-$i" &
done