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

        println("the source array")
        println(srcdata.toList)
        println(srcdata.toList)
    }

    def swap(srcdata: Array[Int], p: Int, r: Int):Unit = {
	}

    def partition(srcdata: Array[Int], p: Int, r:Int, partitionType:Int):Int = {
		var i:Int = 0
		var j:Int = 0
		var x:Int = 0

		if(partitionType>0){
			i = r
			swap(srcdata,i,r)
		}
		x = srcdata[r]
		i = p-1
		for( j <- p to (r-1) ){
			if( srcdata[j]<=x ){
				i = i+1
				swap(srcdata,i,j)
			}
		}
		swap(srcdata,i+1,r)
		return(i+1)
	}

    def quick_sort(srcdata: Array[Int], p: Int, r: Int, partitionType: Int):Unit = {
        var q = 0

		if( p<r ){
			q = partition(srcdata,p,r)
			quick_sort(srcdata,p,q-1,partitionType)
			quick_sort(srcdata,q+1,p,partitionType)
		}
    }

}
