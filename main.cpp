#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> rotLeft(vector<int> a, int d) {
    int n=a.size();
    if(d==n)return a;
    vector<int> out = a;
    for(int i=0;i<n;i++){
        if(i<d)out[i-d+n]=a[i];
        else out[i-d]=a[i];
    }
    return out;
}

int main() {

    return 0;
}
