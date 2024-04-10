#!/bin/bash

# Request 8 cores on a single node for 5 minutes
#SBATCH --cpus-per-task=32
#SBATCH -t 00:05:00
#SBATCH --exclusive
#SBATCH --mem-bind=local


# This is to suppress the warning about not finding a GPU resource
export OMPI_MCA_mpi_cuda_support=0

# Env variable to reduce performance variability
export OMP_PROCESSOR_BIND=true

# Set the number of OpenMP threads to 8
#export OMP_NUM_THREADS=16

# Run the executable
for ((i=1;i<=32;i*=2));
do
   echo $i  
   export OMP_NUM_THREADS=$i
   echo "Number of threads is $i" >> problem4.out
   ./problem4 8192 >> problem4.out
done
