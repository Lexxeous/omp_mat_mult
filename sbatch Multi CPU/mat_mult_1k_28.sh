#!/bin/bash
#SBATCH --nodes=1
#SBATCH --cpus-per-task=28
#SBATCH --time=00:00:15

./omp_mat_mult 1000 28