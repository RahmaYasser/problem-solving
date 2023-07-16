#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int miniLength=1e6,st=0,end=0,sum=nums[0],l;
    while(st<nums.size()&&end<nums.size()){
        if(sum<target){
            end++;
            if(end<nums.size())sum+=nums[end];
        }
        else {
            l=end-st+1;
            if(l<miniLength)miniLength = l;
            sum-=nums[st];
            st++;
        }
    }
    if(miniLength==1e6)return 0;else return miniLength;
}
int main() {
    cout <<"SOLVING ON LEETCODE\n";
    int miniLength=1e6;
    cout << miniLength;
    return 0;
}
