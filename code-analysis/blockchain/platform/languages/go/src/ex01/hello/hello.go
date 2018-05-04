package main

import (
	"fmt"
	"os"
	"ex01/stringutil"
)

func main() {
	fmt.Printf("Hello, world.\n")
	fmt.Printf(stringutil.Reverse("!oG ,olleH"))
	var s, sep string
	for i := 1; i < len(os.Args); i++ {
		s += sep + os.Args[i]
		sep = " " 
	}
	fmt.Println(s)

}
