#!/bin/bash
#SBATCH --nodes=1
#SBATCH --cpus-per-task=28
#SBATCH --time=00:20:00

./omp_mat_mult 7000 28