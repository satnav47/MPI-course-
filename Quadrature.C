#include <stdio.h>
#include <math.h>
#include <mpi.h>
#define STEPS 27720 

int main(int argc, char *argv[]) {
	int rank, nproc, start, end, i;
	double total = 0, result; 

	MPI_Init(&argc, &argv); //Initial MPI call
	MPI_Comm_size(MPI_COMM_WORLD, &nproc); 
	MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
	start = rank*(STEPS/(double)nproc);
	end = (rank+1)*(STEPS/(double)nproc)-1; 

	for(i = start; i <= end; i++) {
		total += exp(-pow(10.0*((i+0.5)/(STEPS+1)),2));
	}
	printf("Total from process %d is %f\n", rank, total); 

	MPI_Reduce(&total, &result, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

	if (rank == 0) {
		printf("Grand total %f, integral %f\n", result, 10*result/STEPS);
	}

	MPI_Finalize();

	return 0; 
}