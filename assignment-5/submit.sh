#!/bin/bash

# Allocate 20 cores on a single node for 5 minutes
#SBATCH -N 1
#SBATCH --ntasks=20
#SBATCH -t 00:05:00
#SBATCH --exclusive


rm junks.txt
mpirun -np 1 ./prefix sample-input.data 16 junks.txt
python3 compare.py

