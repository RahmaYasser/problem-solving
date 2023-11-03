#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define FOR( i, S, E ) for(int i=(int)S ; i<=(int)E ; i++ )

/*
 * bfs,
 * node is pair representing coordinates,
 * start point is queue of points that should start simultaneously ,
 * solution is to find the latest traversed node for the graph
*/
int dirR[4]={1,-1,0,0};
int dirC[4]={0,0,1,-1};

// if child can be visited, return true
bool valid(int r, int c,int R,int C,vector<vector<bool>> &graph){
    return r>0 && r<=R && c>0 && c<=C && !graph[r][c];
}
void bfs(vector<vector<bool>> &graph,pair<int,int> &latestNode,queue<pair<int,int>>&startPoints, int n,int m){
    queue <pair<int,int>> q;
    pair<int,int> node;
    int x,y;
    while(!startPoints.empty()){
        node=startPoints.front();
        startPoints.pop();
        graph[node.first][node.second]=true;
        q.push(node);
    }
    while(!q.empty()){
        node=q.front();
        latestNode=node;
        q.pop();
        FOR(i,0,3){
            x = node.first+dirR[i];
            y = node.second+dirC[i];
            if(valid(x,y,n,m,graph)){
                graph[x][y]=true;
                q.push({x,y});
            }
        }
    }
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,m,k,x,y;
    cin >>n>>m>>k;
    vector<vector<bool>> graph;
    queue<pair<int,int>>startPoints;
    while(k--){
        cin >>x>>y;
        startPoints.push({x,y});
    }
    FOR(i,0,n){
        vector<bool> x(m+1,false);
        graph.push_back(x);
    }
    pair<int,int> latestNode;
    bfs(graph,latestNode,startPoints,n,m);
    cout << latestNode.first << " " << latestNode.second;
    return 0;

}