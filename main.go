package main

import (
	"fmt"
	"strconv"
)
func maximum69Number (num int) int {
    str:=strconv.Itoa(num)
	for i,_ :=range str {
		if str[i]=='6'{
			res:=str[:i]+"9"+str[i+1:]
			num,_= strconv.Atoi(res)
			break
		}
	}
	return num
}

func main(){
	fmt.Println(maximum69Number(9669))
}