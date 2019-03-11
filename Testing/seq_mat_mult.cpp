#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
//#include <omp.h> // OpenMP library

using namespace std;

int main()
{
	int mat_size = 4500;
	time_t start, end;

	time(&start);

	// if(argc < 3)
	// {
	// 	cerr << "Please enter a command of the form: ./<prog_name> <matrix_size> <num_of_threads>" << endl; //print error
	// 	return -1; // return error
	// }

	// if(argc < 2)
	// {
	// 	cerr << "Please enter a command of the form: ./<prog_name> <matrix_size>" << endl; //print error
	// 	return -1; // return error
	// }

	// int mat_size = atoi(argv[1]); // user specified matrix size
	// int thread_count = atoi(argv[2]); // user specified thread count

	srand(time(NULL));

	cout << endl << "Dynamically allocating matricies of size " << mat_size << "..." << endl;
	int** A = new int*[mat_size];
	for(int i = 0; i < mat_size; i++)
		A[i] = new int[mat_size];

	int** B = new int*[mat_size];
	for(int i = 0; i < mat_size; i++)
		B[i] = new int[mat_size];

	int** C = new int*[mat_size];
	for(int i = 0; i < mat_size; i++)
		C[i] = new int[mat_size];

	int curr_cell;


	cout << "Initializing random values..." << endl;
	for(int i = 0; i < mat_size; i++)
	{
		for(int j = 0; j < mat_size; j++)
		{
			A[i][j] = rand() % 10;
			B[i][j] = rand() % 10;
		}
	}


	// cout << endl;
	// cout << "Printing Matrix A:" << endl;
	// for(int i = 0; i < mat_size; i++)
	// {
	// 	for(int j = 0; j < mat_size; j++)
	// 	{
	// 		cout << A[i][j] << "\t";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;


	// cout << "Printing Matrix B:" << endl;
	// for(int i = 0; i < mat_size; i++)
	// {
	// 	for(int j = 0; j < mat_size; j++)
	// 	{
	// 		cout << B[i][j] << "\t";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;


	cout << "Generating matrix C by square matrix multiplication (C = A•B)..." << endl;
	for(int i = 0; i < mat_size; i++)
	{
    for(int j = 0; j < mat_size; j++)
    {
      curr_cell = 0; // reset curr_cell value
      for(int k = 0; k < mat_size; k++)
      {
        curr_cell += A[i][k]*B[k][j];
			}
      C[i][j] = curr_cell; 
      // cout << curr_cell << "\t";
		}
    // cout << endl;
	}
	// cout << endl;


	cout << "Deleting dynamically allocated matricies from memory..." << endl;
	for(int i = 0; i < mat_size; i++)
  	delete[] A[i];
	delete[] A;

	for(int i = 0; i < mat_size; i++)
  	delete[] B[i];
	delete[] B;

	for(int i = 0; i < mat_size; i++)
  	delete[] C[i];
	delete[] C;


	time(&end);

	double exec_time = difftime (end, start);
	cout << "Matrices of square size " << mat_size << " were dynamically allocated, initialized, multiplied, and "
			 << "dynamically deleted in " << exec_time << " seconds." << endl;

	return 0;
}