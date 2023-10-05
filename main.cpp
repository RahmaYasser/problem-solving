#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int EuclideanGCD(int a,int b){
    if(a==0&&b!=0)return b;
    if(b==0)return a;
    if(a==b)return a;
    if(a>b)return EuclideanGCD(a-b,b);
    else return EuclideanGCD(a,b-a);
}
int power(int base,int p){
    if(p==0)return 1;
    int ans=power(base,p>>1);
    if(p%2==0)return ans*ans;
    else return ans*ans*base;
}
int gcdModRecursive(int min,int max){
    if(min==0)return max;
    return gcdModRecursive(max%min,min);
}
int main(){
    int t,n,lcm,gcd,mn,mx;
    cin>>t;
    while(t--){
        cin >>n;
        lcm=1;
        for(int i=2;i<=n;i++){
            // lcm=6 i=4
            if(i<lcm){
                mn=i;
                mx=lcm;
            }else{
                mn=lcm;
                mx=i;
            }
            gcd=gcdModRecursive(mn,mx);
            lcm = lcm*i/gcd;
        }
        cout <<lcm<<"\n";
    }
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