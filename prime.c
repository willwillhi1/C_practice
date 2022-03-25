#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <mpi.h>
#define N 88888888

bool array[100000000];
int main(int argc, char *argv[]){
	int id;
	int p;
	MPI_Init(&argc,&argv);
	MPI_Barrier(MPI_COMM_WORLD);
	MPI_Comm_rank(MPI_COMM_WORLD,&id);
	MPI_Comm_size(MPI_COMM_WORLD,&p);
	double start,end;
	int count=0;
	start = clock();
	for(int k=2;k*k<=N;k++){
		if(array[k-1]==1){
			continue;
		}
	        else{
			for(int i=0;k*(k+i)<=N;i++){
				array[k*(k+i)-1]=1;
			}	
		}
	}
	end = clock();
	for(int i=1;i<N;i++){
		if(array[i]==0){
			count++;
			//printf("%d\n",i+1);
		}
	}
	printf("%d)\n",id);
	printf("%d\n",count);
	printf("%f\n",(end-start)/CLOCKS_PER_SEC);
	MPI_Finalize();
	return 0;
}
