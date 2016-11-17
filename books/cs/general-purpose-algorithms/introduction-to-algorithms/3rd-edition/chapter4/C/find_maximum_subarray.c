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

struct rtnData find_maximum_subarray(double* srcdata, int low, int high);
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
	struct rtnData rtn;
    int idx, jdx, sign;

    srand(time(NULL));
    for( idx=0; idx<DATASETSIZE; idx++ ){
        srcdata[idx] = rand()*1.0/RAND_MAX;
		sign = ( srcdata[idx] > 0.5 )?-1:1;
		srcdata[idx] *= sign;
    }
	printArray(srcdata);

	rtn = find_maximum_subarray(srcdata, 0, DATASETSIZE-1);
	printf("(left,right,sum) = (%d,%d,%f)\n",rtn.max_left,rtn.max_right,rtn.sum);
	printf("DBL_MAX = %f\n",-1*DBL_MAX);
	return 0;
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
	struct rtnData rtn,rtn_left,rtn_right,rtn_crossing;
	int mid=0;

	if( high == low ){
		rtn.max_left = low;
		rtn.max_right = high;
		rtn.sum = srcdata[low];
	}else{
		mid = (int)floor((low+high)/2);
		rtn_left = find_maximum_subarray(srcdata,low,mid);
		rtn_right = find_maximum_subarray(srcdata,mid+1,high);
		rtn_crossing = find_max_crossing_subarray(srcdata,low,mid,high);

		if( (rtn_left.sum >= rtn_right.sum) && (rtn_left.sum >= rtn_crossing.sum) ){
			rtn = rtn_left;
		}else if ( (rtn_right.sum >= rtn_left.sum) && (rtn_right.sum >= rtn_crossing.sum) ){
			rtn = rtn_right;
		}else{
			rtn = rtn_crossing;
		}
	}
	
	return rtn;	
}

