package main

import "fmt"

func validPalindrome(s string) bool {
    if IsPalindrome(s) { return true }
	l := 0;
    h := len(s)-1;

	
    for(h > l){
        if(s[l] != s[h]){
			sSlice:=[]rune(s)
			sSlice2:=[]rune(s)
			newS:=append(sSlice[0:l], sSlice[l+1:]...)
			if IsPalindrome(string(newS)){ return true} else { 
				newS2:=append(sSlice2[0:h], sSlice2[h+1:]...)
				if IsPalindrome(string(newS2)){ return true} else {
					return false
				}
			}
        }
		l++
		h--
    }
	return false
}

func IsPalindrome(s string) bool {
	l := 0;
    h := len(s)-1;

    for(h > l){
        if(s[l] != s[h]){
			return false
        }
		l++
		h--
    }
	return true
}
func main(){
	fmt.Println(validPalindrome("abxaxcba"))
}