import scala.util.Random
import scala.collection._

object HeapSort{
    def main(args: Array[String]):Unit = {
        val dataSetSize = 10
        var srcdata = util.Random.shuffle(100 to 999).take(dataSetSize).toArray;
        var aaa = new Array[Int](dataSetSize)
        var bbb = new Array[Int](aaa.size)
        val digit = 3
        var idx:Int = 0
        var jdx:Int = 0
		var rtn: (Int,Int,Int) = (0,0,0)

        println(s"the source array, ${srcdata.toList}")
        //heap_sort(srcdata,dataSetSize)
		rtn = find_max_subarray( srcdata, 1, dataSetSize )
        println(s"the sorted data, ${srcdata.toList}")
    }

    def swap(srcdata: Array[Int], p: Int, r: Int):Unit = {
        var temp = srcdata(p)
        srcdata(p) = srcdata(r)
        srcdata(r) = temp
    }

    def left( i: Int ): Int = {
        return(2*i)
    }
    def right( i: Int ): Int = {
        return(2*i+1)
    }


    def max_heapify(srcdata: Array[Int], len: Int, i: Int):Unit = {
        val l = left(i)
        val r = right(i)
        var largest = 0

        if( l<len && srcdata(l)>srcdata(i) ){
            largest = l
        }else largest = i
        if( r<len && srcdata(r)>srcdata(largest) ){
            largest = r
        }

        if( largest != i ){
            swap(srcdata,largest,i)
            max_heapify(srcdata,len,largest)
        }

    }

    def build_max_heap(srcdata: Array[Int], len: Int):Unit = {
        var idx: Int = 0

        for( idx <- len/2 to 0 by -1 ){
            max_heapify(srcdata,len,idx)
        }
    }

    def heap_sort(srcdata: Array[Int], len: Int):Unit = {
        var idx: Int = 0
        var datasize = len

        build_max_heap(srcdata,len)
        for( idx <- len-1 to 1 by -1 ){
            swap(srcdata,0,idx)
            datasize = datasize -1
            max_heapify(srcdata,datasize,0)
        }
    }

	def find_max_crossing_subarray( srcdata: Array[Int], low: Int, mid: Int, high: Int ):(Int, Int, Int) = {
		var left_sum: Int = -1e9.toInt
		var right_sum: Int = -1e9.toInt
		var sum: Int = 0
		var max_left: Int = mid
		var max_right: Int = mid
		var idx: Int = 0
		for( idx <- mid to low by -1 ){
			sum = sum + srcdata(idx)
			if( sum > left_sum ){
				left_sum = sum
				max_left = idx
			}
		}
		
		sum = 0
		for( idx <- mid+1 to high ){
			sum = sum + srcdata(idx)
			if( sum > right_sum ){
				right_sum = sum
				max_right = idx
			}
		}
		
		return( (max_left,max_right,left_sum+right_sum) )
	}

	def find_max_subarray( srcdata: Array[Int], low: Int, high: Int ):(Int, Int, Int) = {
		var mid: Int = low
		var rtn: (Int, Int, Int) = (0,0,0)
		var rtn_left: (Int, Int, Int) = (0,0,0)
		var rtn_right: (Int, Int, Int) = (0,0,0)
		var rtn_crossing: (Int, Int, Int) = (0,0,0)

		if( low == high ){
			rtn = (low, high, srcdata(low))
		}else{
			mid = (low+high)/2	
			rtn_left = find_max_subarray(srcdata,low,mid)
			rtn_right = find_max_subarray(srcdata,mid+1,high)
			rtn_crossing = find_max_crossing_subarray(srcdata,low,mid,high)
			
			if( (rtn_left._3>rtn_right._3) && (rtn_left._3>rtn_crossing._3) ){
				rtn = rtn_left
			}else if( (rtn_right._3>rtn_left._3) && (rtn_right._3>rtn_crossing._3) ){
				rtn = rtn_right
			}else{
				rtn = rtn_crossing
			}
		}
		return(rtn)
	}
}
