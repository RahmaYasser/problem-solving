package main

import "fmt"

/*
1 1 1 2 2 3 3 3 3 3
*/
func sortColors(nums []int) {
	quickSort(0, len(nums)-1, nums)
}
func quickSort(low int, high int, arr []int) {
	if low < high {
		pivotIndex := partition(low, high, arr)
		quickSort(low, pivotIndex-1, arr)
		quickSort(pivotIndex+1, high, arr)
	}
}
func partition(low int, high int, arr []int) int {
	pivot := arr[high]
	i := low - 1
	for j := low; j < high; j++ {
		if arr[j] <= pivot {
			i++
			arr[i], arr[j] = arr[j], arr[i]
		}
	}
	//swap(i+1, high, arr)
	arr[i+1], arr[high] = arr[high], arr[i+1]
	return i + 1
}
func main() {
	var nums = []int{2, 0, 1}
	sortColors(nums)
	fmt.Println(nums)
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
