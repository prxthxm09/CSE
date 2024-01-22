#include "mpi.h"
#include <stdio.h>
int main(int argc, char* argv[]){
	int rank, size, x;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Status status;
	if(rank==0){
		int n = 4;
		int arr[] = {5,6,7,8};
		//MPI_Buffer_attach(arr,n);
		for(int i =1;i<n;i++)
			MPI_Send(&arr[i],1,MPI_INT,i,1,MPI_COMM_WORLD);
		//MPI_Buffer_detach(arr,&n);
		printf("From Process 0 : %d\n",arr[rank]*arr[rank]);
	}
	else if(rank == 1){
		int x;
		MPI_Recv(&x,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
		printf("From Process 1 : %d\n",x*x*x);
	}
	else if(rank == 2){
		int x;
		MPI_Recv(&x,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
		printf("From Process 2 : %d\n",x*x);
	}
	else if(rank == 3){
		int x;
		MPI_Recv(&x,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
		printf("From Process 3 : %d\n",x*x*x);
	}
	MPI_Finalize();
	return 0;
}