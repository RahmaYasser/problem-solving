package main
import "sort"

func findContentChildren(g []int, s []int) int {
    sort.Ints(g)
    sort.Ints(s)
    sPointer:=0
    gPointer:=0
    ans:=0
    sLength:=len(s)
    gLength:=len(g)
    for sPointer<sLength && gPointer<gLength{
        if g[gPointer]<=s[sPointer] {
            ans+=1
            sPointer+=1
        }
        gPointer+=1
    }
    return ans
}
func main(){
    
}