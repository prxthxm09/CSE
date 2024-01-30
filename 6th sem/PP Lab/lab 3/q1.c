#include "mpi.h"
#include <stdio.h>
long factorial(int n)  
    {  
    if (n == 0)  
        return 1;  
    else  
        return(n * factorial(n-1));  
    }  
int main(int argc, char *argv[])
    {
        int rank,size,N,A[10],B[10], c, i;
        MPI_Init(&argc,&argv);
        MPI_Comm_rank(MPI_COMM_WORLD,&rank);
        MPI_Comm_size(MPI_COMM_WORLD, &size);
        if(rank==0)
            {
                N=size;
                printf("Enter %d values:\n",N);
                for(i=0; i<N; i++)
                    scanf("%d",&A[i]);
            }
        MPI_Scatter(A,1,MPI_INT,&c,1,MPI_INT,0,MPI_COMM_WORLD);
        printf("I have received %d in process %d\n",c,rank);
        c = factorial(c);
        MPI_Gather(&c,1,MPI_INT,B,1,MPI_INT,0,MPI_COMM_WORLD);
        if(rank==0)
            {
     int s = 0;
        for(i = 0; i < N; i++) 
            s += B[i];
        printf("Sum of factorials is: %d\n", s);
            }
    MPI_Finalize();
    return 0;
}