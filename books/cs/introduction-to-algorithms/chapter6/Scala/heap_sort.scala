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

        println(s"the source array, ${srcdata.toList}")
        heap_sort(srcdata,dataSetSize)
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

}
