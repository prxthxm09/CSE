#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char *argv []) {
	int size, rank;
	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	if (rank == 0) {	
	int k;
	printf("%d. Enter a number : ", rank);
	scanf("%d",&k);
	k += 1;
		MPI_Send(&k, 1, MPI_INT, rank + 1, rank, MPI_COMM_WORLD);
		printf("\nNumber sent by process %d is %d.\n", rank, k);
		MPI_Recv(&k, 1, MPI_INT, size - 1, size - 1, MPI_COMM_WORLD, &status);
		printf("Number received by process %d is %d.\n", rank, k);
	} 
	else {
		int k;
		MPI_Recv(&k, 1, MPI_INT, rank - 1, rank - 1, MPI_COMM_WORLD, &status);
		printf("Number received by process %d is %d.\n", rank, k);
		k += 1;
		MPI_Send(&k, 1, MPI_INT, (rank + 1) % size, rank, MPI_COMM_WORLD);
		printf("Number sent by process %d is %d.\n", rank, k);
	} 
MPI_Finalize();
}