#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int GCD(int a,int b){
    if(a==0&&b!=0)return b;
    if(b==0)return a;
    if(a==b)return a;
    if(a>b)return GCD(a-b,b);
    else return GCD(a,b-a);
}
int power(int base,int p){
    if(p==0)return 1;
    int ans=power(base,p>>1);
    if(p%2==0)return ans*ans;
    else return ans*ans*base;
}
int main(){
    int n,m;
    cin >>n>>m;
    cout << GCD(n,m);
    return 0;
}

int gcd(int a, int b){
    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        }
        else {
            b = b % a;
        }
    }
    if (a == 0) {
        return b;
    }
    return a;
}