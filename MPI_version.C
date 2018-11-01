#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]){
	int major,minor;
	printf("Compile-time MPI version is %d.%d\n",MPI_VERSION, MPI_SUBVERSION);
	MPI_Get_version(&major,&minor);
	printf("Run-time MPI version is %d.%d\n",major,minor);
	return 0;
}