package main

import (
	"fmt"
	"strconv"
)

func convertTime(current string, correct string) int {
	ans:=0
    currentH,_:=strconv.Atoi(current[:2])
    correctH,_:=strconv.Atoi(correct[:2])

	currentM,_:=strconv.Atoi(current[3:])
    correctM,_:=strconv.Atoi(correct[3:])

	minut:=correctH*60+correctM - (currentH*60+currentM)

	ans += minut/60
	minut = minut%60
	ans += minut/15
	minut = minut%15
	ans += minut/5
	minut = minut%5
	ans += minut
	return ans
}
func main(){
	
	fmt.Println(convertTime("08:35","11:00"))
}