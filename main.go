package main

func getRow(rowIndex int) []int {
	var firstRow []int
	firstRow = append(firstRow, 1)
	for i := 1; i <= rowIndex; i++ {
		var secondRow []int
		secondRow = append(secondRow, 1)
		for j := 1; j < len(firstRow); j++ {
			secondRow = append(secondRow, firstRow[j]+firstRow[j-1])
		}
		secondRow = append(secondRow, 1)
		firstRow = secondRow
	}
	return firstRow
}
