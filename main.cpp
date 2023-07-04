#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isCovered(vector<vector<int>>& ranges, int left, int right) {
    vector<int> rangedSum(52,0);
    for(auto r:ranges){
        rangedSum[r[0]]++;
        rangedSum[r[1]+1]--;
    }
    for(int i=1;i<rangedSum.size();i++){
        rangedSum[i]+=rangedSum[i-1];
    }
    for(int i=left;i<=right;i++){
        if(!rangedSum[i])return false;
    }
    return true;
}
int main() {
    cout <<"SOLVING ON LEETCODE";
    return 0;
}
