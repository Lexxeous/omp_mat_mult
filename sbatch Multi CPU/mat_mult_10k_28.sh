#!/bin/bash
#SBATCH --nodes=1
#SBATCH --cpus-per-task=28
#SBATCH --time=02:00:00

./omp_mat_mult 10000 28