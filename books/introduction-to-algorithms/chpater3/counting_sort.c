/*
* counting sort algorithm
* introduction to algorithm, 3rd edition, chapter 3
* secure c programming
* high performance
* c11 standard
*/

#include <stdio.h>
#include <stdlib.h>

#define DATASETSIZE 100

int main( void )
{
	int testdata[DATASETSIZE];
	int rtndata[DATASETSIZE];
	int tempdata[DATASETSIZE];
	size_t idx,jdx;
	
	for(idx=0;idx<DATASETSIZE;idx++){
		testdata[idx] = rand() % DATASETSIZE;
		tempdata[idx] = 0;
		printf("%zu\t,%d,\n",idx,testdata[idx]);
	}

	for(jdx=0;jdx<DATASETSIZE;jdx++){
		tempdata[testdata[jdx]] = tempdata[testdata[jdx]] + 1;
	}
	for(idx=0;idx<DATASETSIZE;idx++){
		printf("%zu\t,%d,\n",idx,tempdata[idx]);
	}
	
	for(idx=1;idx<DATASETSIZE;idx++){
		tempdata[idx] = tempdata[idx] + tempdata[idx-1];
	}
	for(idx=0;idx<DATASETSIZE;idx++){
		printf("%zu\t,%d,\n",idx,tempdata[idx]);
	}

	for(jdx=DATASETSIZE;jdx>=1;jdx--){
		rtndata[tempdata[testdata[jdx-1]]] = testdata[jdx-1];
		tempdata[testdata[jdx-1]] = tempdata[testdata[jdx-1]] - 1;
	}

	for(idx=0;idx<DATASETSIZE;idx++){
		printf("%zu\t,%d,\n",idx,rtndata[idx]);
	}

	return 0;
}
