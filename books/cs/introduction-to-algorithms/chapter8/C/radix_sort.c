/*
* Radix sorting algorithm
* introduction to algorithm, 3rd edition, chapter 8
* secure c programming
* high performance
* c11 standard,
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DATASETSIZE 10

int counting_sort( int srcdata[], int testdata[], int rtndata[], size_t len );
int getVal( int srcVal, int digit );

int main( void )
{
	int srcdata[DATASETSIZE] = {838, 458, 977, 286, 842, 882, 817, 434, 557, 611};
	int testdata[DATASETSIZE];
	int rtndata[DATASETSIZE];
        int digit = 3;
	size_t idx,jdx;
        
	
	printf("The test data is:\n");
	for(idx=0;idx<DATASETSIZE;idx++){
		printf("%zu\t,%d,\n",idx,srcdata[idx]);
	}

	for( jdx=0; jdx<digit; jdx++){
		for(idx=0;idx<DATASETSIZE;idx++){
			testdata[idx] = getVal(srcdata[idx],jdx);
		}
		
		printf("For the %zuth digit sorting:\n", jdx);
		counting_sort( srcdata, testdata, rtndata, DATASETSIZE );

		for(idx=0;idx<DATASETSIZE;idx++){
			srcdata[idx] = rtndata[idx];
			printf("%zu\t,%d,\n",idx,rtndata[idx]);
		}
	}

	printf("For the final sorted data:\n");
	for(idx=0;idx<DATASETSIZE;idx++){
		printf("%zu\t,%d,\n",idx,srcdata[idx]);
	}

	printf("....%d\n", (int)pow(10,3));
	return 0;
}

int counting_sort( int srcdata[], int testdata[], int rtndata[], size_t len )
{
	int tempdata[DATASETSIZE];
	size_t idx,jdx;
	
	for(idx=0;idx<DATASETSIZE;idx++){
		tempdata[idx] = 0;
	}

	printf("The temp data is:\n");
	for(jdx=0;jdx<DATASETSIZE;jdx++){
		tempdata[testdata[jdx]] = tempdata[testdata[jdx]] + 1;
	}
	for(idx=0;idx<DATASETSIZE;idx++){
		printf("%zu\t,%d,\n",idx,tempdata[idx]);
	}
	
	for(idx=1;idx<DATASETSIZE;idx++){
		tempdata[idx] = tempdata[idx] + tempdata[idx-1];
	}
	printf("The temp data is:\n");
	for(idx=0;idx<DATASETSIZE;idx++){
		printf("%zu\t,%d,\n",idx,tempdata[idx]);
	}

	for(jdx=DATASETSIZE;jdx>=1;jdx--){
		//rtndata[tempdata[testdata[jdx-1]]] = testdata[jdx-1];
		rtndata[tempdata[testdata[jdx-1]]] = srcdata[jdx-1];
		tempdata[testdata[jdx-1]] = tempdata[testdata[jdx-1]] - 1;
	}

	return 0;
}


int getVal( int srcVal, int digit )
{
	return (srcVal/(int)pow(10,digit)) % 10;
}
