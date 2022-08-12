package main

func subarraySum(nums []int, k int) int {
	n := len(nums)
	ans := 0
	for i := 0; i < n; i++ {
		sum := 0
		for j := i; j < n; j++ {
			sum += nums[j]
			if sum == k {
				ans++
			}
		}
	}
	return ans
}
func main() {
	nums := []int{1}
	println(subarraySum(nums, 0))
}
