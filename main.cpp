#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> leftRightDifference(vector<int>& nums) {
    int l=nums.size();
    int prefixSum[l];
    vector<int>answer(l);
    prefixSum[0]=nums[0];
    for(int i=1;i<l;i++){
        prefixSum[i]=nums[i]+prefixSum[i-1];
    }
    answer[0] = abs(prefixSum[l-1]-prefixSum[0]);
    for(int i=1;i<l;i++){
        answer[i] = abs(prefixSum[i-1]-(prefixSum[l-1]-prefixSum[i]));
    }
    return answer;
}
int main() {
    cout <<"SOLVING ON LEETCODE";
    return 0;
}
