#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define FOR( i, S, E ) for(int i=(int)S ; i<=(int)E ; i++ )
/*
 * codeforces C. Mail stamps
 * get leaf node in undirected graph, then traverse the graph from this node as start point
 */

void dfs(int current,map<int,vector<int>>&adj,map<int,bool> &visited){
    visited[current]=true;
    cout << current<<" ";
    for(auto child : adj[current]){
        if(!visited[child]){
            dfs(child,adj,visited);
        }
    }
}
int main(){
    int n,x,y,leaf=-1;
    cin>>n;
    map<int,vector<int>> adj;
    map<int,bool> visited;

    FOR(i,1,n){
        cin >>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        visited[x]=false;
        visited[y]=false;
    }
    for(auto it:adj){
        if(it.second.size()==1){
            leaf=it.first;
            break;
        }
    }
    dfs(leaf,adj,visited);
    return 0;
}
