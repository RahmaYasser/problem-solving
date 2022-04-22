package main

import "fmt"

func lemonadeChange(bills []int) bool {
	c5:=0
	c10:=0
    for _,cust:=range bills{
		if cust==5{
			c5++
		}else if cust==10 {
			if c5==0{ return false}
			c10++
			c5--
		} else{
			if c5==0{ return false}
			if c10>0{
				c10--
				c5--
			}else {
				c5-=3
			}
		}
		if c5<0 || c10<0 {
			return false
		}
	}
    return true
}
func main(){
	x := []int{10}
	fmt.Println(lemonadeChange(x))
}