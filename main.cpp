#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define FOR( i, S, E ) for(int i=(int)S ; i<=(int)E ; i++ )

// distant path of a tree
int ans;
void dfs(vector<vector<int>> &adj,int parent,int node,int count,int & mx,int &distantNode) {
    if (count > mx) {
        mx = count;
        distantNode = node;
        ans=count;
    }
    int child;
    FOR(i, 0, adj[node].size() - 1) {
        child = adj[node][i];
        if (child != parent) {
            dfs(adj, node, child, count + 1, mx, distantNode);
        }
    }
}
int main(){
    int n,x,y;
    cin >>n;
    vector<vector<int>> adj(n+1);
    vector<bool> visited(n+1,false);
    FOR(i,1,n-1){
        cin >> x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int mx=-1,distantNode;
    dfs(adj,-1,x,1,mx,distantNode);
    mx=-1;
    dfs(adj,-1,distantNode,1,mx,distantNode);
    cout <<ans-1<<"\n";
    return 0;
}