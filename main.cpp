#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
/*
 * Is bipartite graph?
 * 1. color the src node
 * 2. traverse to children to mark with opposite color
 * 3. if any child is already colored with the same color as parent, return false
 * 4. return true if all graph is traversed
 * 5. note that, call bfs for each connected component
 */



bool isBipartite(vector<vector<int>>&adj,vector<int>&colors,int start){
    queue<int> q;
    q.push(start);
    colors[start]=1;
    int current,child;
    while(!q.empty()){
        current=q.front();
        q.pop();
        for(int i=0;i<adj[current].size();i++){
            child=adj[current][i];
            if(colors[child]==0){
                colors[child]=-colors[current];
                q.push(child);
            }
            else{
                if(colors[child]==colors[current])return false;
            }
        }
    }
    return true;
}
int main(){
    int t,n,e,x,y;
    cin>>t;
    for(int o=1;o<=t;o++){
        cin>>n>>e;
        vector<vector<int>>adj(n+1);
        vector<int>colors(n+1,0);// not colored
        for(int i=0;i<e;i++){
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        cout <<"Scenario #"<<o<<":\n";
        bool bipartite=true;
        for(int i=1;i<=n;i++){
            if(colors[i]==0){
                if(!isBipartite(adj,colors,i)){
                    bipartite=false;
                    break;
                }
            }
        }
        if(bipartite)cout <<"No suspicious bugs found!\n" ;
        else cout <<"Suspicious bugs found!\n";
    }
    return 0;
}
