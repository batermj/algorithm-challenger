#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define DATASETSIZE 10

struct node{
	double dValue;
	struct node * pNext;
};

void insert_sort(struct node ** pBucket, double dValue);
int main(void){
	double srcdata[DATASETSIZE];
	struct node bArray[DATASETSIZE];
	struct node *pNext = NULL;

	int idx, jdx;

	srand(time(NULL));
	for( idx=0; idx<DATASETSIZE; idx++ ){
		srcdata[idx] = rand()*1.0/RAND_MAX;
		printf("the data is %f,%f\n",srcdata[idx],floor((float)(srcdata[idx]*DATASETSIZE)) );
		bArray[idx].dValue = -1;
		bArray[idx].pNext = NULL;
	}

	for( idx=0; idx<DATASETSIZE; idx++ ){
		jdx = (int)(floor((float)(srcdata[idx]*DATASETSIZE)));
		insert_sort(&(bArray[jdx].pNext),srcdata[idx]);
		if(bArray[jdx].pNext == NULL ){
			printf("the insertion failed.\n");
		}
	}

	for( idx=0; idx<DATASETSIZE; idx++ ){
		printf("\nthe %dth bucket:\n",idx);
		pNext = bArray[idx].pNext;
		while( pNext != NULL ){
			printf("%f, ", pNext->dValue);
			pNext = pNext->pNext;
		}
		printf("\n");
	}
}


void insert_sort(struct node ** pBucket, double dValue){
	struct node *pNext = NULL, *pNext2=NULL, *myBucket=*pBucket;
	printf("the dValue is %f\n",dValue);
	if( myBucket == NULL ){
		printf("the myBucket is empty\n");
		myBucket = (struct node *)malloc(sizeof(struct node));
		myBucket->dValue = dValue;
		myBucket->pNext = NULL;
		*pBucket = myBucket;
	}else{
		printf("the myBucket is not empty\n");
		pNext = myBucket;
		while( pNext != NULL ){
			if( pNext->dValue <= dValue ){
				myBucket = pNext;
				pNext = pNext->pNext;
			}else break;
		}

		pNext2 = (struct node *)malloc(sizeof(struct node));
		pNext2->dValue = dValue;
		pNext2->pNext = NULL;

		if(pNext == myBucket){
			pNext2->pNext = myBucket;
			*pBucket = pNext2;
		}else{
			myBucket->pNext = pNext2;
			pNext2->pNext = pNext;
		}
	}
}
