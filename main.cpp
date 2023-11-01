#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define FOR( i, S, E ) for(int i=(int)S ; i<=(int)E ; i++ )
/*
 * codeforces D. Road Map
 */

void dfs(vector< vector<int> > &adj,int current, int parent, vector<int> &p){
    p[current] = parent;
    for(auto child : adj[current]){
        if(p[child]==-1){
            dfs(adj,child,current,p);
        }
    }
}

int main(){
    int n,r1,r2,node;
    cin>>n>>r1>>r2;
    vector< vector<int> > adj(n+1);
    vector<int> p(n+1,-1); // from 1 to n needed
    FOR(i,1,n){
        if(i!=r1){
            cin >> node;
            adj[i].push_back(node);
            adj[node].push_back(i);
        }
    }
    dfs(adj,r2,-1,p);
    FOR(i,1,n){
        if(i!=r2) cout <<p[i]<<" ";
    }
    return 0;
}
