import scala.util.Random

object QuickSort{
    def main(args: Array[String]):Unit = {
        val dataSetSize = 10
        var srcdata = util.Random.shuffle(100 to 999).take(dataSetSize).toArray;
        var aaa = new Array[Int](dataSetSize)
        var bbb = new Array[Int](aaa.size)
        val digit = 3
        var idx:Int = 0
        var jdx:Int = 0

        println(s"the source array, ${srcdata.toList}")
    	quick_sort(srcdata,0, dataSetSize-1, 0)
        println(s"the result, ${srcdata.toList}")
    }

    def insertion_sort(srcdata: Array[Int]):Unit = {
    }

}
