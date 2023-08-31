#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int maximumToys(vector<int> prices, int k) {
    int count=0;
    sort(prices.begin(),prices.end());
    for(auto p:prices){
        if(p<=k){
            count++;
            k-=p;
        }
        else break;
    }
    return count;
}

int main() {

    return 0;
}
