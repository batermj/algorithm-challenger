#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <float.h>

#define DATASETSIZE 10

struct rtnData{
	int max_left;
	int max_right;
	double sum;
};

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

	printf("DBL_MAX = %f\n",-1*DBL_MAX);
	return 0;
}

void swap(double* srcdata,int i,int j){
    double temp;

    temp = srcdata[i];
    srcdata[i] = srcdata[j];
    srcdata[j] = temp;
}

int partition(double* srcdata,int p,int r, int partitionType){
    double x;
    int i,j;

	if(partitionType>0){
		i = (int)((rand()*1.0/RAND_MAX)*(r-p)+p);
		printf("partition at %d,%d,%d\n",p,r,i);
		swap(srcdata,i,r);	
	}
    x = srcdata[r];

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

struct rtnData find_max_crossing_subarray(double* srcdata, int low, int mid, int high){
	struct rtnData rtn;
	double sum,left_sum,right_sum;
	int idx;
	
	sum = 0;
	left_sum = -1*DBL_MAX;
	for(idx=mid; idx>=low;idx--){
		sum += srcdata[idx];
		if( sum > left_sum ){
			left_sum = sum;
			rtn.max_left = idx;
		}
	}
	
	sum = 0;
	right_sum = -1*DBL_MAX;
	for(idx=mid+1;idx<=high;idx++){
		sum += srcdata[idx];
		if( sum>right_sum ){
			right_sum = sum;
			rtn.max_right = idx;
		}
	}
	rtn.sum = left_sum + right_sum;
	return rtn;
}

struct rtnData find_maximum_subarray(double* srcdata, int low, int high){
	struct rtnData rtn;
	int mid=0;

	if( high == low ){
		rtn.max_left = low;
		rtn.max_right = high;
		rtn.sum = srcdata[low];
		return rtn;
	}
	
	return rtn;	
}

