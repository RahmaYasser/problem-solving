package main

import (
	"sort"
)

func singleNumber(nums []int) int {
	nums = append(nums, 30005)
	sort.Ints(nums)
	for i := 0; i < len(nums); {
		if nums[i] == nums[i+1] {
			i += 2
		} else {
			return nums[i]
		}
	}
	return -30005
}

func main() {
	var nums = []int{2, 2, 5, 4, 4, 8, 8}
	println(singleNumber(nums))
}

/*
res		num
0		2
2		2
0		5
5		4		0101  01000 -> 1101
9		4
13		8
*/
