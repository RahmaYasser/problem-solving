#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int binarySearch(int target,vector<int>&primes){
    int st=0,end=78499,mid;
    while(st<end){
        mid=st+(end-st+1)/2;
        if(primes[mid]==target)return mid;
        if(primes[mid]>target)end=mid-1;
        else st=mid;
    }
    return end;
}
int main(){
    int MAX_N=1000009;
    int n,t;
    cin >>t;
    vector<bool>isPrime(MAX_N,true);
    vector<int>primes;
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i*i<=MAX_N;i++){
        if(isPrime[i]){
            for(int y=i+i;y<MAX_N;y+=i){
                isPrime[y]=false;
            }
        }
    }
    for(int i=2;i<isPrime.size();i++){
        if(isPrime[i])primes.push_back(i);
    }
    vector<ll>prefixSum(primes.size());
    prefixSum[0]=2;
    for(int i=1;i<primes.size();i++){
        prefixSum[i]=primes[i]+prefixSum[i-1];
    }
    while(t--) {
        cin >> n;
        if(n==1)cout <<0;
        else{
            n= binarySearch(n,primes);
            cout <<prefixSum[n]<<"\n";
        }
    }
    return 0;
}


