#!/bin/bash
#SBATCH --nodes=1
#SBATCH --cpus-per-task=28
#SBATCH --time=00:01:00

./omp_mat_mult 2000 28