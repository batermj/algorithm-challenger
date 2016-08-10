import java.math.*;
import java.util.*;

/**
*
* counting sort algorithm
* introduction to algorithm, 3rd edition, chapter 3
* clean the workspace and memory
*/
public class CountingSort
{
	public static void main(String[] args){
		final int DATASET_SIZE = 10;
		final int DATASET_MAX  = 100;
		int[] aaa = new int[DATASET_SIZE];
		int[] bbb = new int[DATASET_SIZE+1];
		int[] ccc;
		int   idx;
		int   k;
		int   total;

		k = 0;
		for(idx=0;idx<DATASET_SIZE;idx++){
			aaa[idx] = (int)((Math.random())*DATASET_MAX);
			if( k < aaa[idx] ) k = aaa[idx];
			System.out.println("index = " + idx + ", value = " + aaa[idx]);
		}
		System.out.println("the max value in the array is " + k );
		
		ccc = new int[k+1];
		for(idx=0;idx<DATASET_SIZE;idx++){
			ccc[aaa[idx]] += 1;
		}
		total=0;
		for(idx=0;idx<=k;idx++){
			total += ccc[idx];
			ccc[idx] = total;
		}
		
		for(idx=DATASET_SIZE-1;idx>=0;idx--){
			bbb[ccc[aaa[idx]]] = aaa[idx];
			ccc[aaa[idx]] -= 1;
		}
		for(idx=0;idx<DATASET_SIZE;idx++){
			System.out.println("index = " + idx + ", value = " + bbb[idx]);
		}
		
	}
	
}
