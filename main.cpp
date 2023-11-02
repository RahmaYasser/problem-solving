#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define FOR( i, S, E ) for(int i=(int)S ; i<=(int)E ; i++ )
/*
 * pick up sticks UVA
 * idea: check if directed graph has a cycle
 */

stack<int> ans;
// return true if solution is possible (there is no cycle), false if there is a cycle
bool dfs(vector<vector<int>> &adj,vector<int> &visited,int node){
    visited[node]=1;
    int child;
    bool possible=true;
    FOR(i,0,adj[node].size()-1){
        child = adj[node][i];

        if(visited[child]==0){
             possible=possible&&dfs(adj,visited,child);
        }
        else if (visited[child]==1){
            return false;
        }
    }
    visited[node]=-1;
    ans.push(node);

    return possible;
}
int main(){
    int n,m,x,y;

    while (scanf("%d %d", &n, &m) && (n || m)) {
        while(!ans.empty())ans.pop();
        vector<vector<int>> adj(n+1);
        vector<int>visited(n+1,0);
        while (m--) {
            scanf("%d %d", &x, &y);
            adj[x].push_back(y);
        }
        bool possible=true;
        FOR(i,1,n){
            if(visited[i]==0){
                if(!dfs(adj,visited,i)){
                    possible=false;
                    break;
                }
            }
        }
        if(!possible){
            cout <<"IMPOSSIBLE"<<"\n";
        }
        else{
            while(!ans.empty()){
                cout << ans.top()<<"\n";
                ans.pop();
            }
        }
    }
    return 0;
}