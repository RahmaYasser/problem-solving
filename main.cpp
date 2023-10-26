#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


// check if it's a tree
/*
 * 1. edges=nodes-1
 * 2. one connected component -> flood fill then check if all nodes are visited
 * 3. no cycles -> can be verified from 1, and visited array
 */

void dfs(vector<vector<int>> &adj,int currentNode,vector<bool>&visited){
    visited[currentNode]=true;
    for(int i=0;i<adj[currentNode].size();i++){
        int child=adj[currentNode][i];
        if(!visited[child]){
            dfs(adj,child,visited);
        }
    }
}

int main(){
    int n,m,u,v;
    cin>>n>>m;
    if(m!=n-1) {
        cout << "NO\n";
    }
    else{
        vector<vector<int>>adj(n+1);
        vector<bool>visited(n+1,false);
        visited[0]=true;
        for(int i=0;i<m;i++){
            cin >> u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(adj,adj[u][0],visited);
        for(auto bitReference:visited){
            if(!bitReference){
                cout << "NO";
                return 0;
            }
        }
        cout <<"YES";
    }
    return 0;
}
