#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define DATASETSIZE 10

void insertion_sort(double* srcdata, int len);
void main(void){
    double srcdata[DATASETSIZE];
    int idx, jdx;

    srand(time(NULL));
    for( idx=0; idx<DATASETSIZE; idx++ ){
        srcdata[idx] = rand()*1.0/RAND_MAX;
    }
    for( idx=0; idx<DATASETSIZE; idx++ ){
        if(idx%10 == 0) printf("\n\n");
        printf(" %f, ",srcdata[idx]);
    }
    printf("\n");
    insertion_sort(srcdata,DATASETSIZE);
    for( idx=0; idx<DATASETSIZE; idx++ ){
        if(idx%10 == 0) printf("\n\n");
        printf(" %f, ",srcdata[idx]);
    }
    printf("\n");
}

void insertion_sort(double* srcdata,int len){
	int idx = 0,jdx = 0;
	double dValue = 0;

	for( idx=1;idx<len;idx++ ){
		dValue = srcdata[idx];
		jdx = idx - 1;
		while( (jdx >= 0) && (srcdata[jdx]>dValue) ){
			srcdata[jdx+1] = srcdata[jdx];
			jdx = jdx - 1;
		} 
		srcdata[jdx+1] = dValue;
	}
}
