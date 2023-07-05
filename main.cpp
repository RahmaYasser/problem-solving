#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int pivotInteger(int n) {
    int sum = n*(n+1)/2;
    for(int i=1;i<=n;i++){
        if(i*(i+1)/2==sum-((i-1)*i)/2)return i;
    }
    return -1;
}
int main() {
    cout <<"SOLVING ON LEETCODE";
    return 0;
}
