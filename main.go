package main

func subarraySum(nums []int, k int) int {
	m := make(map[int]int)
	m[0] = 1 // sum to 0 will always be here
	sum := 0
	ans := 0
	for _, v := range nums {
		sum += v
		ans += m[sum-k]
		m[sum]++
	}
	return ans
}
func main() {
	nums := []int{1}
	println(subarraySum(nums, 0))
}
