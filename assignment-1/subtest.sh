#!/bin/bash

# Allocate 16 cores on a single node for 5 minutes
#SBATCH -N 1
#SBATCH --ntasks=4
#SBATCH -t 00:05:00
#SBATCH --exclusive

make
# This is to suppress the warning about not finding a GPU resource
export OMPI_MCA_mpi_cuda_support=0

# Load OpenMPI
module load openmpi/gcc

# Run the executable
mpirun -np 4 ./testcode life.1.512x512.data 500 512 512 &> testcode.out
cat testcode.out
