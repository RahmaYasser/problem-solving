package main

import (
	"fmt"
	"sort"
)

/*
1 1 1 2 2 3 3 3 3 3
*/
func threeSum(nums []int) [][]int {
	var res [][]int

	if len(nums) < 3 {
		return res
	}

	sort.Ints(nums)

	for i := 0; i < len(nums)-2; i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}

		left, right := i+1, len(nums)-1

		for left < right {
			target := nums[i] + nums[left] + nums[right]

			if target == 0 {
				res = append(res, []int{nums[i], nums[left], nums[right]})
				left, right = left+1, right-1

				for left < right && nums[left] == nums[left-1] {
					left++
				}

				for left < right && nums[right] == nums[right+1] {
					right--
				}
			} else if target > 0 {
				right--
			} else {
				left++
			}
		}
	}

	return res
}
func main() {
	var nums = []int{10}
	fmt.Println(threeSum(nums))

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
