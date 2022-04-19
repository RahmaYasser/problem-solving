package main

import (
	"fmt"
)

// func longestPalindrome(s string) int {
// 	ans:=0
// 	var alphabet[26] int
// 	var alphabetUpper[26] int
//     for _,c :=range s{
// 		if c>='a' && c<='z'{
// 			alphabet[c-'a']++
// 		} else {
// 			alphabetUpper[c-'A']++
// 		}
// 	}
// 	maxOdd:=0
// 	for _,freq:=range alphabet{
// 		if freq%2==1 {
// 			if freq>maxOdd{
// 				maxOdd=freq
// 			}
// 		} else{
// 			ans+=freq
// 		}
// 	}
// 	// for _,freq:=range alphabet{
// 	// 	fmt.Print(freq," ")
// 	// }
// 	for _,freq:=range alphabetUpper{
// 		if freq%2==1 {
// 			if freq>maxOdd{
// 				maxOdd=freq
// 			}
// 		} else{
// 			ans+=freq
// 		}
// 	}
// 	//fmt.Println("ans so far ", ans)
// 	maxOddAppeared:=false
// 	//tmp:=0
// 	for _,freq:=range alphabet{
// 		if freq%2==1 {
// 			if freq<maxOdd{
// 				//fmt.Println("less than max odd",freq-1)
// 				ans+=(freq-1)
// 			}else if freq==maxOdd{
// 				if !maxOddAppeared{
// 					//fmt.Println("max odd first time", maxOdd)
// 					ans+=maxOdd
// 					maxOddAppeared=true
// 				} else{
// 					//fmt.Println("less than max odd",freq-1)
// 					ans+=(freq-1)
// 				}
// 			}
// 		}
// 	}
// 	for _,freq:=range alphabetUpper{

// 		// fmt.Println("----------- ")
// 		// fmt.Println(freq)

// 		if freq%2==1 {
// 			//fmt.Print("hi")
// 			if freq<maxOdd{
// 				ans+=(freq-1)
// 			} else if freq==maxOdd{
// 				if !maxOddAppeared{
// 					ans+=maxOdd
// 					maxOddAppeared=true
// 				} else{
// 					ans+=freq-1
// 				}
// 			}
// 		}
// 	}
//     return ans
// }
func longestPalindrome(s string) int {
    letters := []byte(s)
	fmt.Println(letters)
    pair := make([]bool, 58) // 'A' - 'a' = 32 
    count := 0
    for _, letter := range letters {
        index := letter - 'A'
		//fmt.Println("index ",index)
        if pair[index] {
            pair[index] = false
            count += 2
        } else {
            pair[index] = true
        }
    }
	fmt.Println(pair)
	for index, remain := range pair {
		//fmt.Println(index," ",remain)
		if remain{
			fmt.Println(index)
		}
	}
    for index, remain := range pair {
		fmt.Print(index," " ,remain)
		fmt.Println()
        if remain {
            return count + 1
        }
    }
    return count
}
func main(){
	fmt.Println(longestPalindrome("bbba"))
}