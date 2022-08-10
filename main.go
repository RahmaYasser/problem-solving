package main

import "sort"

func eraseOverlapIntervals(intervals [][]int) int {
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][1] < intervals[j][1]
	})
	res := 0
	i := 0
	for i < len(intervals) {
		j := i + 1
		for j < len(intervals) && intervals[i][1] > intervals[j][0] {
			j++
			res++
		}
		i = j
	}
	return res
}func main() {

}
