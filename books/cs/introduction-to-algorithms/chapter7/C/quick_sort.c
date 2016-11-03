#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define DATASETSIZE 100

void quick_sort(double* srcdata, int p, int r);
void main(void){
    double srcdata[DATASETSIZE];
    int idx, jdx;

    srand(time(NULL));
    for( idx=0; idx<DATASETSIZE; idx++ ){
        srcdata[idx] = rand()*1.0/RAND_MAX;
        printf("the data is %f,%f\n",srcdata[idx],floor((float)(srcdata[idx]*DATASETSIZE)) );
    }
    quick_sort(srcdata,0,DATASETSIZE-1);
    for( idx=0; idx<DATASETSIZE; idx++ ){
        if(idx%10 == 0) printf("\n\n");
        printf(" %f, ",srcdata[idx]);
    }
    printf("\n");
}

void swap(double* srcdata,int i,int j){
    double temp;

    temp = srcdata[i];
    srcdata[i] = srcdata[j];
    srcdata[j] = temp;
}

int partition(double* srcdata,int p,int r){
    double x = srcdata[r];
    int i,j;

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


void quick_sort(double* srcdata, int p, int r){
    int q=0;
    if( p<r ){
        q = partition(srcdata,p,r);
        quick_sort(srcdata,p,q-1);
        quick_sort(srcdata,q+1,r);
    }
}
