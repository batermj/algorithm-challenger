import scala.util.Random

object CountingSort{
	def main(args: Array[String]):Unit = {
		val dataSetSize = 100
		val rnd = new Random
		val aaa = List.fill(10)(Random.nextInt(10))
		var bbb = new Array[Int](aaa.size+1)
		var ccc = new Array[Int](aaa.max+1)
		var idx = 0
		var total = 0

		println(aaa)
		println(aaa.max)
		println("the size of the array bbb")
		println(bbb.size)
		println(ccc.size)
		for( idx <- aaa ){
			println(idx)
			ccc(idx) = ccc(idx) + 1
		}
		println(ccc.toList)
		idx = 0
		total = 0
		for( idx <- 0 to (ccc.size-1) ){
			total = total + ccc(idx)
			ccc(idx) = total
		}
		println(ccc.toList)

		for(idx <- aaa.reverse){
			bbb(ccc(idx)) = idx
			ccc(idx) = ccc(idx) - 1
		}
		println(bbb.toList)
	}
}
