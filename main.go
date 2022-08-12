package main

func productExceptSelf(nums []int) []int {
	size := len(nums)
	prefix := 1
	ans := make([]int, size)
	for i := 0; i < size; i++ {
		ans[i] = prefix
		prefix *= nums[i]
	}
	prefix = 1
	for i := size - 1; i >= 0; i-- {
		ans[i] = prefix
		prefix *= nums[i]
	}
	return ans
}
func main() {
	nums := []int{1, 2, 3, 4}
	productExceptSelf(nums)
}
