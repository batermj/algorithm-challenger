import scala.util.Random

object CountingSort{
        def main(args: Array[String]):Unit = {
                val dataSetSize = 100
                val aaa = List.fill(10)(Random.nextInt(10))
                var bbb = new Array[Int](aaa.size)

                println("the array aaa")
                println(aaa)

                counting_sort(aaa,bbb);
                println(bbb.toList)
        }

        def counting_sort(aaa: List[Int], bbb: Array[Int]):Unit = {
                var ccc = new Array[Int](aaa.max+1)
                var idx = 0
                var total = 0

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

                for(idx <- aaa.reverse){
                        bbb(ccc(idx)-1) = idx
                        ccc(idx) = ccc(idx) - 1
                }
        }
}
