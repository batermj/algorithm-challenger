#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <float.h>

#define DATASETSIZE 100

void printArray(double* srcdata, int p, int r);
void merge_sort(double* srcdata, int p, int r);
void main(void){
    double srcdata[DATASETSIZE];
    int idx, jdx;

    srand(time(NULL));
    for( idx=0; idx<DATASETSIZE; idx++ ){
        srcdata[idx] = rand()*1.0/RAND_MAX;
    }
	printArray(srcdata,0,DATASETSIZE-1);
    merge_sort(srcdata,0,DATASETSIZE-1);
	printArray(srcdata,0,DATASETSIZE-1);
}

void printArray(double* srcdata, int p, int r){
	printf("(p,r) = (%d,%d)\n",p,r);
	for( int idx=p;idx<=r;idx++ ){
		printf("%f, ", srcdata[idx]);
	}
	printf("\n");
}

void merge(double* srcdata, int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    int idx,jdx,kdx;
    double ldata[n1+1];
    double rdata[n2+1];

    ldata[n1] = rdata[n2] = 2;//DBL_MAX;
    for( idx = 0; idx<n1; idx++ ){
        ldata[idx] = srcdata[p+idx];
    }
    for( jdx = 0; jdx<n2; jdx++ ){
        rdata[jdx] = srcdata[q+jdx+1];
    }

    idx = jdx = 0;
    for( kdx = p; kdx <= r; kdx++ ){
        if( ldata[idx] <= rdata[jdx] ){
            srcdata[kdx] = ldata[idx];
            idx++;
        }else{
            srcdata[kdx] = rdata[jdx];
            jdx++;
        }
    }

}

void merge_sort(double* srcdata, int p, int r){
    int q;
    if( p<r ){
        q = floor((p+r)/2);
        merge_sort(srcdata,p,q);
        merge_sort(srcdata,q+1,r);
        merge(srcdata,p,q,r);
    }
}

