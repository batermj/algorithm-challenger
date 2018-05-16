package main

import (
	"fmt"
)

func main(){

	s := "hello, golang"
	fmt.Println(len(s))
	fmt.Println(s[0], s[7])

	fmt.Println(s[0:5])
	fmt.Println(s[:5]) 
	fmt.Println(s[7:])
	fmt.Println(s[:])

	fmt.Println("goodbye" + s[5:])

	literals := "салем казақща! 您好，哈萨克语！Hello Kazakh Language!"
	fmt.Println(literals);

}
