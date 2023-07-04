#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minStartValue(vector<int>& nums) {
    int mini=1000,sum=0;
    for(auto n:nums){
        sum+=n;
        if(sum<mini){
            mini=sum;
        }
    }
    mini=1-mini;
    if(mini<1)return 1;
    return mini;
}
int main() {
    cout <<"SOLVING ON LEETCODE";
    return 0;
}
