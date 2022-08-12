package main

func productExceptSelf(nums []int) []int {
	size := len(nums)
	prefix := make([]int, size)
	suffix := make([]int, size)
	prefix[0] = 1
	suffix[size-1] = 1
	for i := 1; i < size; i++ {
		prefix[i] = prefix[i-1] * nums[i-1]
	}
	for i := size - 2; i >= 0; i-- {
		suffix[i] = suffix[i+1] * nums[i+1]
	}
	for i := 0; i < size; i++ {
		nums[i] = suffix[i] * prefix[i]
	}
	return nums
}
func main() {
	nums := []int{1, 2, 3, 4}
	productExceptSelf(nums)
}
