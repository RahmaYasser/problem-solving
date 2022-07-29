package main

/*
1 1 1 2 2 3 3 3 3 3
*/
func merge(intervals [][]int) [][]int {
	var res [][]int
	quickSort(0, len(intervals)-1, intervals)
	iIndex := 0
	res = append(res, []int{intervals[0][0], intervals[0][1]})
	for i := 1; i < len(intervals); i++ {
		overlapX, overlapY := overlap(res[iIndex][0], res[iIndex][1], intervals[i][0], intervals[i][1])
		if overlapX != -1 {
			res[iIndex][0] = overlapX
			res[iIndex][1] = overlapY
		} else {
			iIndex++
			res = append(res, []int{intervals[i][0], intervals[i][1]})
		}
	}
	return res
}
func overlap(x1 int, y1 int, x2 int, y2 int) (int, int) {
	// there is no max.int in go :)
	var y int
	if y2 > y1 {
		y = y2
	} else {
		y = y1
	}
	if x2 >= x1 && x2 <= y1 {
		return x1, y
	}
	return -1, -1
}
func quickSort(low int, high int, arr [][]int) {
	if low < high {
		pivotIndex := partition(low, high, arr)
		quickSort(low, pivotIndex-1, arr)
		quickSort(pivotIndex+1, high, arr)
	}
}
func partition(low int, high int, arr [][]int) int {
	pivot := arr[high][0]
	i := low - 1
	for j := low; j < high; j++ {
		if arr[j][0] <= pivot {
			i++
			arr[i][0], arr[j][0] = arr[j][0], arr[i][0]
			arr[i][1], arr[j][1] = arr[j][1], arr[i][1]
		}
	}
	//swap(i+1, high, arr)
	arr[i+1][0], arr[high][0] = arr[high][0], arr[i+1][0]
	arr[i+1][1], arr[high][1] = arr[high][1], arr[i+1][1]
	return i + 1
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
