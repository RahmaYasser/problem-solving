#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int largestAltitude(vector<int>& gain) {
    int sum=0,max=0;
    for(auto g:gain){
        sum+=g;
        if(sum>max)max=sum;
    }
    return max;
}
int main() {
    cout <<"SOLVING ON LEETCODE";
    return 0;
}
