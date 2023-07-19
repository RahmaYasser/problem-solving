#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp{{0, 0}};
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (!mp.count(sum % k))
                mp[sum % k] = i + 1;
            else if (mp[sum % k] < i)
                return true;
        }
        return false;
}
int main() {
    cout <<"SOLVING ON LEETCODE\n";
    return 0;
}
