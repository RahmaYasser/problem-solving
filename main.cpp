#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


// PRIMES
bool IsPrime(long long n){
    bool tPrime=false;
    for(int i=2;i*i<=n;i++){
        if(i*i==n){
            n/=i;
            tPrime= true;
            break;
        }
    }
    if(!tPrime)return false;
    if(n%2==0||n==1)return n==2;
    for(int i=3;i*i<=n;i+=2){
        if(n%i==0)return false;
    }
    return true;
}

// DIVISORS
vector<int> findDivisor(int n){
    vector<int> v;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            v.push_back(i);
            if(i!=n/i)v.push_back(n/i);
        }
    }
    return v;
}

// PRIMES FACTORS
vector<int> findPrimeFactor(int n){
    vector<int> v;
    while(n%2==0){
        n/=2;
        v.push_back(2);
    }
    for(int i=3;i*i<=n;i+=2){
        while(n%i==0){
            n/=i;
            v.push_back(i);
        }
    }
    // what if this number is prime?
    if(n>1)v.push_back(n);
    for(auto x:v)cout <<x<<" ";
    return v;
}

int countPrimes(int n){
    if (n==0)return 0;
    vector<bool>isPrime(n,true);
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i*i<=n;i++){
        if(isPrime[i]){
            for(int y=i+i; y<n;y+=i){
                isPrime[y]=false;
            }
        }
    }
    int count=0;
    for(auto x:isPrime)if(x)count++;
    return count;
}
int main(){
    int MAX_N=1000009;

    vector<bool> isPrime(MAX_N,true);
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i*i<=MAX_N;i++){
        if(isPrime[i]){
            for(int y=i+i; y<=MAX_N;y+=i){
                isPrime[y]=false;
            }
        }
    }
    vector<ll>tPrimesList;
    for(ll i=2;i<isPrime.size();i++){
        if(isPrime[i]){
            tPrimesList.push_back(i*i);
        }
    }
    int n;cin>>n;
    ll x;
    while(n--){
        cin>>x;
        // binary search
        if(binary_search(tPrimesList.begin(),tPrimesList.end(),x))cout<<"YES\n";
        else cout <<"NO\n";
    }
    return 0;
}