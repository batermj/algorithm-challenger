/**
* counting sort algorithm
* introduction to algorithm, 3rd edition, chapter 3
*
*/

import Darwin
import Cocoa

let dataset_size = 10
let max: UInt32 = 10
var aaa:[Int] = [Int]()
var bbb:[Int] = [Int]()
var ccc:[Int] = [Int]()
var total:Int = 0

for index in 0 ... (dataset_size-1) {
	aaa.append( Int(arc4random_uniform(max)) )
	print("index = \(index), value = \(aaa[index])\n")
}

let k = aaa.maxElement()
print(k)
ccc = Array(count:(k!+1), repeatedValue:0)
bbb = Array(count:(dataset_size+1),repeatedValue:0)

for index in aaa {
	ccc[index] += 1
	print("value = \(index)\n")
}
for index in 0...k! {
	total += ccc[index]
	print("index = \(index), value = \(ccc[index]), total = \(total)\n")
	ccc[index] = total
}

for index in aaa.reverse() {
	bbb[ccc[index]] = index
	ccc[index] -= 1
}
for index in 0 ... dataset_size {
	print("index = \(index), value = \(bbb[index])\n")
}
