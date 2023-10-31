#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

/*
 * count max level of nodes for each connected component
 * return max count
 */

int bfs(vector<vector<int>>&adj,int start){
    int level=0,current,size;
    queue<int>q;
    q.push(start);
    while(!q.empty()){
        size=q.size();
        while(size--){
            current=q.front();
            q.pop();
            for(int i : adj[current]){
                q.push(i);
            }
        }
        level++;
    }
    return level;
}

int main(){
    int n,x;
    cin>>n;
    vector<vector<int>> adj(n+1);
    vector<int>startingPoints;
    for(int i=1;i<=n;i++){
        cin >> x;
        if(x==-1)startingPoints.push_back(i);
        else adj[x].push_back(i);
    }
    int mxLevel=-1,lvl;
    for(auto s:startingPoints){
        lvl=bfs(adj,s);
        mxLevel=max(mxLevel,lvl);
    }
    cout <<mxLevel<<"\n";


    return 0;
}
