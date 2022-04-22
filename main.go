package main

import (
	"fmt"
)

func canThreePartsEqualSum(arr []int) bool {
    total := 0
    
    for _, v := range arr {
        total += v
    }
    
    if total % 3 != 0 {
        return false
    }
    
    target, part, count := total / 3, 0, 0
    
    for k, v := range arr {
        part += v
        if part == target {
            part = 0
            count++
            if count == 2 && k != len(arr) - 1 {
                return true
            }
        }
    }
    
    return false
}
// func main(){
	
// 	fmt.Println(minimumMoves("XXOX"))
// }