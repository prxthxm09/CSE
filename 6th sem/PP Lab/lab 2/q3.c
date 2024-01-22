#include "mpi.h"
#include <stdio.h>
int main(int argc, char *argv[])
{
int rank,size,n=4;
int buff[100];
MPI_Init(&argc,&argv);
int x[]={5,6,7,8};
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD, &size);
MPI_Status status;
if(rank==0){
	MPI_Buffer_attach(buff, sizeof(buff));
for(int i=1;i<4;i++){
MPI_Bsend(&x[i],1,MPI_INT,i,1,MPI_COMM_WORLD);
printf("I have send %d from process 0\n",x[i]);}
int a=sizeof(buff);
MPI_Buffer_detach(buff,&a);
}
else if (rank % 2==0){
	int a;
MPI_Recv(&a,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
printf("I have received %d in process %d\n",a,rank);
printf("Square root is:%d\n",a*a);
}
else{
	int a;
MPI_Recv(&a,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
printf("I have received %d in process %d\n",a,rank);
printf("Cube root is:%d\n",a*a*a);
}
MPI_Finalize();
return 0;
}