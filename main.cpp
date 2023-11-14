#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define FOR( i, S, E ) for(int i=(int)S ; i<=(int)E ; i++ )

int main(){
    int n,edges,startNode=1,to,from,cost;
    cin >>n>>edges;
    vector< vector<pair<int,int>>> adj(n+1); // to, cost
    FOR(i,1,edges){
        cin >>from>>to>>cost;
        adj[from].push_back({to,cost});
        adj[to].push_back({from,cost});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq; // cost,node
    vector<pair<int,int>> distance(n+1,{INT_MAX,-1}); // cost,parent
    distance[startNode] = {0,-1};
    pq.push({0,startNode});
    int currentNode,currentCost,childCost,childNode,total;
    while(!pq.empty()){
        currentNode=pq.top().second;
        currentCost=pq.top().first;
        pq.pop();
        FOR(i,0,adj[currentNode].size()-1){
            childCost = adj[currentNode][i].second;
            childNode = adj[currentNode][i].first;
            if(childNode == distance[currentNode].second)continue;
            total = currentCost+childCost;
            if(total < distance[childNode].first){
                distance[childNode].first = total;
                distance[childNode].second = currentNode;
                pq.push({total,childNode});
            }
        }
    }
    stack<int> ans;
    ans.push(n);
    currentNode = distance[n].second;
    while(currentNode!=1){
        if(currentNode==-1) {
            cout <<-1;
            return 0;
        }
        ans.push(currentNode);
        currentNode = distance[currentNode].second;
    }
    ans.push(1);
    while(!ans.empty()){
        cout << ans.top()<<" ";
        ans.pop();
    }
    return 0;
}


