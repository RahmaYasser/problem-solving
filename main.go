package main

import (
	"fmt"
)

func main(){
	var h,n int
	fmt.Scanf("%d %d",&n,&h)
	var friends[1000]int
	one:=0
	two:=0
	for i := 0; i < n; i++ {
		fmt.Scan(&friends[i])
		if friends[i]>h{
			two+=2
		}else{
			one+=1
		}
	} 
	fmt.Print(one+two)
}