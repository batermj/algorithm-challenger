import scala.util.Random
import scala.collection._

object BucketSort{
	def main(args: Array[String]):Unit = {
		val dataSetSize = 10
		val srcdata = List.fill(10)(Random.nextDouble)
		var aaa = new Array[mutable.Buffer[Double]](dataSetSize)

		for( idx <- 0 until dataSetSize ){
			aaa(idx) = mutable.Buffer[Double]()
		}
		println("the source array")
		println(srcdata)

		for( idx <- 1 until srcdata.size ){
			srcdata(idx) match {
				case x: Double if (x < 1) =>
					insert2List(aaa((srcdata(idx)*dataSetSize).floor.toInt),srcdata(idx))
					println(s"$x")
				case _ => println(s"bigger")
			}
		}

		for( idx <- 0 until dataSetSize ){
			println(s"the ${idx}th buffer is ${aaa(idx)}")
		}
		for( idx <- 0 until dataSetSize ){
			var bbb = mutable.Buffer[Double]()
			insert_sort(aaa(idx).toList,bbb)
			for( jdx <- 0 until bbb.size ){
				aaa(idx)(jdx) = bbb(jdx)
			}
			println(s"the ${idx}th buffer is ${aaa(idx)}, $bbb")
		}
	}

	def insert_sort(srcdata: List[Double], bbb: mutable.Buffer[Double]):Unit = {
		for( dValue <- srcdata.sorted ) bbb += dValue
	}

	def insert2List(subBuffer: mutable.Buffer[Double], value: Double):Unit = {
		subBuffer += value
	}
}
