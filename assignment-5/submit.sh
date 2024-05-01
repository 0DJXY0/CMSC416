#!/bin/bash

# Allocate 16 cores on a single node for 5 minutes
#SBATCH -N 1
#SBATCH --ntasks=16
#SBATCH -t 00:05:00
#SBATCH --exclusive

make
module load gcc/9.4.0 openmpi/4.1.1/gcc/9.4.0/zen2
module load charmpp

mpirun -np 16 ./prefix sample-input.data 8 junks.txt

