package main

import "math"

func increasingTriplet(nums []int) bool {
	var (
		x        = math.MaxInt64
		y        = math.MaxInt64
		z        = math.MaxInt64
		xChanged bool
		yChanged bool
		zChanged bool
	)

	for i := 0; i < len(nums); i++ {
		if nums[i] < x || i == 0 {
			x = nums[i]
			xChanged = true
			continue
		}

		if nums[i] > x && nums[i] < y {
			y = nums[i]
			yChanged = true
			continue
		}

		if nums[i] > y && nums[i] < z {
			z = nums[i]
			zChanged = true
		}

		if xChanged && yChanged && zChanged {
			return true
		}
	}

	if xChanged && yChanged && zChanged {
		return true
	}

	return false
}
func main() {

}
