ckage main

import (
    "fmt"
        "time"
    "math/rand"
)

const dataset_size = 100
const dataset_max_value = 100

func main() {
	var aaa[dataset_size]int
	var bbb[dataset_size+1]int
	var ccc[dataset_max_value]int

	max_value := 0
	total := 0


	r := rand.New(rand.NewSource(time.Now().UnixNano()))
	for idx:=0; idx<dataset_size; idx++ {
		aaa[idx] = r.Intn(dataset_max_value)
		if( max_value < aaa[idx] ){
			max_value = aaa[idx]
		}
	}
	fmt.Println(aaa)

	for idx:=0; idx<dataset_size; idx++ {
		ccc[aaa[idx]] += 1
	}
	for idx:=0; idx<=max_value; idx++ {
		total += ccc[idx]
		ccc[idx] = total
	}
	fmt.Println(ccc)
	for idx:=dataset_size-1; idx>=0; idx-- {
		bbb[ccc[aaa[idx]]] = aaa[idx]
		ccc[aaa[idx]] -= 1
	}
	fmt.Println(bbb)
}
