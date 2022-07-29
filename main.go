package main

import "fmt"

type MyHashMap struct {
	m []int
}

func Constructor() MyHashMap {
	return MyHashMap{
		m: make([]int, 1000005),
	}
}

func (this *MyHashMap) Put(key int, value int) {
	this.m[key] = value + 1
}

func (this *MyHashMap) Get(key int) int {
	if this.m[key] == 0 {
		return -1
	}
	return this.m[key] - 1
}

func (this *MyHashMap) Remove(key int) {
	this.m[key] = 0
}
func main() {
	obj := Constructor()
	obj.Put(10, 20)
	obj.Put(0, 20)
	obj.Put(5, 20)
	obj.Put(7, 20)
	param_2 := obj.Get(10)
	fmt.Println(param_2)
	obj.Remove(10)
	obj.Remove(0)
	obj.Remove(5)
	obj.Remove(7)
	fmt.Println(obj.m)
}
