#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findMiddleIndex(vector<int>& nums) {
    vector<int> prefixSum(nums.size()+1,0);
    for(int i=1;i<prefixSum.size();i++){
        prefixSum[i] = nums[i-1]+prefixSum[i-1];
    }
    //if(prefixSum[0] == prefixSum[prefixSum.size()-1]-prefixSum[1])return 0;
    for(int i=1;i<prefixSum.size();i++){
        if(prefixSum[i-1]==prefixSum[prefixSum.size()-1]-prefixSum[i])return i-1;
    }
    return -1;
}
int main() {
    cout <<"SOLVING ON LEETCODE";
    return 0;
}
