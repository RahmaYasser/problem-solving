package main

import (
	"fmt"
)

func longestPalindrome(s string) int {
	ans:=0
	var alphabet[26] int
	var alphabetUpper[26] int
    for _,c :=range s{
		if c>='a' && c<='z'{
			alphabet[c-'a']++
		} else {
			alphabetUpper[c-'A']++
		}
	}
	maxOdd:=0
	for _,freq:=range alphabet{
		if freq%2==1 {
			if freq>maxOdd{
				maxOdd=freq
			}
		} else{
			ans+=freq
		}
	}
	for _,freq:=range alphabetUpper{
		if freq%2==1 {
			if freq>maxOdd{
				maxOdd=freq
			}
		} else{
			ans+=freq
		}
	}
	ans+=maxOdd
    return ans
}
func main(){
	fmt.Println(longestPalindrome("Aa"))
}