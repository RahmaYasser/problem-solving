package main

func singleNumber(nums []int) int {
	var result int
	for i := 0; i < len(nums); i++ {
		result ^= nums[i]
	}
	return result
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
