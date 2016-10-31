import scala.util.Random

object RadixSort{
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
        println(srcdata(0))
        for( jdx <- 0 to digit-1 ){
            for( idx <- 0 to (dataSetSize-1) ){
                aaa(idx) = getVal(srcdata(idx),jdx)
            }
            println(s"For the ${1+jdx} th digit sorting {${aaa.toList}}, the max of it, ${aaa.max}: ")

            counting_sort(srcdata,aaa,bbb)
            for( idx <- 0 to (dataSetSize-1) ){
                srcdata(idx) = bbb(idx)
            }
            println(srcdata.toList)
        }
        println(srcdata.toList)
    }

    def counting_sort(srcdata: Array[Int], aaa: Array[Int], bbb: Array[Int]):Unit = {
        var ccc = new Array[Int](aaa.max+1)
        var idx = 0
        var total = 0

        println(s"the list ccc, ${ccc.toList}")
        for( idx <- aaa ){
            ccc(idx) = ccc(idx) + 1
        }
        println(ccc.toList)
        total = 0
        for( idx <- 0 to (ccc.size-1) ){
            total = total + ccc(idx)
            ccc(idx) = total
        }
        println(ccc.toList)

        for( idx <- (aaa.size-1 to 0 by -1) ){
            bbb(ccc(aaa(idx))-1) = srcdata(idx)
            ccc(aaa(idx)) = ccc(aaa(idx)) - 1
        }
    }


    def pow10(digit: Int): Int = if(digit == 0) 1 else 10 * pow10(digit-1)

    def getVal( srcVal: Int, digit: Int ): Int = {
        return (srcVal/pow10(digit)) % 10;
    }

}
