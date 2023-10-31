#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

/*
 * count number of connected components
 */

void bfs(vector<vector<int>>&adj,vector<bool>&visited,int start){
    visited[start]=true;
    int current;
    queue<int>q;
    q.push(start);
    while(!q.empty()){
        current=q.front();
        q.pop();
        for(int i : adj[current]){
            if(!visited[i]){
                visited[i]=true;
                q.push(i);
            }
        }
    }

}

int main(){
    int n,node,count=0;
    cin>>n;
    vector<bool>visited(n+1);
    vector<vector<int>> adj(n+1);

    for(int i=1;i<=n;i++){
        cin >> node;
        adj[i].push_back(node);
        adj[node].push_back(i);
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            count++;
            bfs(adj,visited,i);
        }
    }
    cout <<count;

    return 0;
}
