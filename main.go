package main

func largestOddNumber(num string) string {
	nums:="13579"
	odd:=false
	for i:=len(num)-1;i>=0;i--{
		for j,_ := range nums{
			if num[i]=='1' || num[i]=='3' || num[i]=='5' || num[i]=='7' || num[i]=='9'{
				odd=true
				break
			}
			if odd{
				return num[:i+1]
			}
		}
	}
	return ""
}

func main(){}