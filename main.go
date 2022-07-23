package main

import (
	"fmt"
	"sort"
)

/*
1 1 1 2 2 3 3 3 3 3
*/
func majorityElement(nums []int) int {
	sort.Ints(nums)
	var count = 1
	length := len(nums)
	for i := 1; i < length; i++ {
		if nums[i-1] == nums[i] {
			count++
		} else {
			if count > length/2 {
				return nums[i-1]
			}
			count = 1
		}
	}
	return nums[length-1]
}

func main() {
	var nums = []int{10}
	fmt.Println(majorityElement(nums))

}

/*
res		num
0		2
2		2
0		5
5		4		0101  01000 -> 1101
9		4
13		8


0011
0101
----
0110
0011
----
0101
0101
----
0000
0001
----
0001
0011
----
0010
0011
----
0001
*/
