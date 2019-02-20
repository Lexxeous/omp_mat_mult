comp:
	g++ -fopenmp -o omp_mat_mult omp_mat_mult.cpp

clean:
	rm omp_mat_mult
	rm slurm*