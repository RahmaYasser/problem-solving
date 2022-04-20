package main
func canPlaceFlowers(flowerbed []int, n int) bool {
    length := len(flowerbed)
    possible:=0
    if length>1{
        if flowerbed[0]==0 && flowerbed[1]==0{
            flowerbed[0] = 1
            possible++
        }
        if flowerbed[length-1]==0 && flowerbed[length-2]==0{
            flowerbed[length-1] = 1
            possible++
        }
        for i:=1;i<length-1;i++{
            if flowerbed[i]==0 && flowerbed[i-1]==0 && flowerbed[i+1]==0{
                flowerbed[i]=1
                possible++
            }
        } 
    } else if length==1{
        if flowerbed[0]==0{
            possible++
        }
    }
    if n > possible {
        return false
    }
    return true
}


func main(){

}