import scala.util.Random

object QuickSort{
    def main(args: Array[String]):Unit = {
        val dataSetSize = 10
        var srcdata = util.Random.shuffle(100 to 999).take(dataSetSize).toArray;

        println(s"the source array, ${srcdata.toList}, the length is ${srcdata.length}")
    	insertion_sort(srcdata)
        println(s"the result, ${srcdata.toList}")
    }

    def insertion_sort(srcdata: Array[Int]):Unit = {
		var idx: Int = 0
		var jdx: Int = 0
		var iValue: Int = 0
		for( idx <- 1 to (srcdata.length-1) ){
			iValue = srcdata(idx)
			jdx = idx - 1
			while( jdx >= 0 && iValue < srcdata(jdx) ){
				println(s"(${idx},${jdx}),${srcdata(jdx+1)},${srcdata(jdx)}, ${iValue}")
				srcdata(jdx+1) = srcdata(jdx)
				jdx = jdx - 1
			}
			srcdata(jdx+1) = iValue
            println(s"jdx=${jdx},${srcdata.toList}")
		}
    }

}
