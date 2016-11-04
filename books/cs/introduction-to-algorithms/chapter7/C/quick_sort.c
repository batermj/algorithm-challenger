#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define DATASETSIZE 10

void quick_sort(double* srcdata, int p, int r, int partitionType);
void printArray(double* srcdata){
	int idx;

    for( idx=0; idx<DATASETSIZE; idx++ ){
        if(idx%10 == 0) printf("\n\n");
        printf(" %f, ",srcdata[idx]);
    }
    printf("\n");
}

int main(void){
    double srcdata[DATASETSIZE];
    int idx, jdx;

    srand(time(NULL));
    for( idx=0; idx<DATASETSIZE; idx++ ){
        srcdata[idx] = rand()*1.0/RAND_MAX;
    }
	printArray(srcdata);
    printf("\nQuick sort algorithm with original partition pivot\n");
    quick_sort(srcdata,0,DATASETSIZE-1,0);
	printArray(srcdata);
    printf("\nQuick sort algorithm with randomized partition pivot\n");
    for( idx=0; idx<DATASETSIZE; idx++ ){
        srcdata[idx] = rand()*1.0/RAND_MAX;
    }
	printArray(srcdata);
    quick_sort(srcdata,0,DATASETSIZE-1,1);
	printArray(srcdata);
	return 0;
}

void swap(double* srcdata,int i,int j){
    double temp;

    temp = srcdata[i];
    srcdata[i] = srcdata[j];
    srcdata[j] = temp;
}

int partition(double* srcdata,int p,int r, int partitionType){
    double x = srcdata[r];
    int i,j;

	if(partitionType>0){
		i = (int)((rand()*1.0/RAND_MAX)*(r-p)+p);
		printf("partition at %d,%d,%d\n",p,r,i);
		swap(srcdata,i,r);	
	}

    i = p-1;
    for(j=p;j<r;j++){
        if( srcdata[j]<=x ){
            i++;
            swap(srcdata,i,j);
        }
    }
    swap(srcdata,i+1,r);
    return i+1;
}


void quick_sort(double* srcdata, int p, int r, int partitionType){
    int q=0;
    if( p<r ){
        q = partition(srcdata,p,r,partitionType);
        quick_sort(srcdata,p,q-1,0);
        quick_sort(srcdata,q+1,r,0);
    }
}
