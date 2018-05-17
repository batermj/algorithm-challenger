package main

import (
	"fmt"
	"unicode/utf8"
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

	fmt.Println("世界","\xe4\xb8\x96\xe7\x95\x8c","\u4e16\u754c","\U00004e16\U0000754c")

	s2 := "Hello, 首都图书馆"
	fmt.Println(len(s2)) 
	fmt.Println(utf8.RuneCountInString(s2))

	s = s2
	for i := 0; i < len(s); {
		r, size := utf8.DecodeRuneInString(s[i:])
		fmt.Printf("%d\t%c\t%d\n", i, r, size)
		i += size
	}

	for i,r := range s2 {
		fmt.Printf("%d\t%c\t%X\n", i, r, r)
	}

	s3 := "1913 жыл, 5 қаңтар"
	fmt.Println(s3)

	s4 := "Астанада 500 домбырашы бір уақытта күй тартты"
	fmt.Println(s4)

	s5 := ` تورابىمىزداعى مازمۇنداردىڭ مەنشىك ۇقىعى شينجياڭ ۇيعۇر اۆتونوميالى رايوندىق حالىق ۇكىمەتى اقپارات كەڭسەسىنە ءتان، جاريالانعان مازمۇنداردى سىلتەمەسىز كوشىرۋگە بولمايدى. كوشىرىپ پايدالانۋعا تۋرا كەلگەندە، «ءتاڭىرتاۋ تورابىنان» الىنعانى انىق ەسكەرتىلۋى ءتيىس، بولماسا زاڭدىق جاۋاپكەرلىگى قۋزاستىرىلادى.`
	fmt.Println(s5)

	s6 := "جىل باسىنان بەرى قازاقستاندا باسپانا قىمباتتادى"
	fmt.Println(s6)

	// "program" in Japanese katakana
	s7 := "このセクションは、ハッカー向けのマニュアルです。 自分の手を汚して何かをしたい人、PHP の内部構造を知ることで自分の理解を深めたい人、 イケてる拡張モジュールを自作したい人。そんな人たちのために用意しました。 このセクションでは、PHP の内部構造を深く掘り下げたり拡張モジュールの書きかたを説明したり、 複雑怪奇なマクロだらけのコードを読み解くヒントを提供したりします。 重要な内部機能はすべて取り上げますが、きちんと理解するには結局はソースを読むことです。"
	fmt.Printf("% c\n", s7) 
	fmt.Printf("% x\n", s7) 
	r2 := []rune(s7)
	fmt.Printf("%x\n", r2) 

}

func HasPrefix(s, prefix string) bool {
	return len(s) >= len(prefix) && s[:len(prefix)] == prefix
}

func HasSuffix(s, suffix string) bool {
	return len(s) >= len(suffix) && s[len(s)-len(suffix):] == suffix
}

func Contains(s, substr string) bool {
	for i := 0; i < len(s); i++ {
		if HasPrefix(s[i:], substr) {
			return true
		} 
	}
	return false
}


