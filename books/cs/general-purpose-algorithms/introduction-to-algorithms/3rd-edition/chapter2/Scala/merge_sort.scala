import scala.util.Random
import scala.collection.mutable.ArrayBuffer

object QuickSort{
    def main(args: Array[String]):Unit = {
        val dataSetSize = 10
        var srcdata = util.Random.shuffle(100 to 999).take(dataSetSize).toArray;

        println(s"the source array, ${srcdata.toList}, the length is ${srcdata.length}")
		merge_sort(srcdata,0,dataSetSize-1)
        println(s"the result, ${srcdata.toList}")
    }

	def merge(srcdata: Array[Int],p: Int, q: Int, r: Int):Unit = {
		var ldata = ArrayBuffer[Int]()
		var rdata = ArrayBuffer[Int]()
		var idx: Int = 0
		var jdx: Int = 0
		var kdx: Int = 0

		for( idx <- p to q ){
			ldata += srcdata(idx)
		}
		ldata += 1000
		for( jdx <- (q+1) to r ){
			rdata += srcdata(jdx)
		}
		rdata += 1000

		idx = 0
		jdx = 0
		for( kdx <- p to r ){
			if( ldata(idx) <= rdata(jdx) ){
				srcdata(kdx) = ldata(idx)
				idx = idx + 1
			}else{
				srcdata(kdx) = rdata(jdx)
				jdx = jdx + 1
			}
		}
	}

	def merge_sort(srcdata: Array[Int],p: Int, r: Int):Unit = {
		var q: Int = 0
		if( p < r ){
			q = (p+r)/2
			merge_sort(srcdata,p,q)
			merge_sort(srcdata,q+1,r)
			merge(srcdata,p,q,r)
		}
	}

}
