#include <bits/stdc++.h>

using namespace std;

#define FOR(i,st,end) for(int i=st;i<=end;i++)
typedef long long ll;
int main() {
    ll n,m,x,y,w;
    cin >>n>>m;
    vector<vector<pair<ll,int>>> transportation(n); // from -> cost,to
    vector<bool> visited(n,false);
    FOR(i,0,m-1){
        cin >>x>>y>>w;
        x--;y--;
        transportation[x].emplace_back( 2 * w,y);
        transportation[y].emplace_back( 2 * w,x);
    }
    vector<ll> cost(n);
    FOR(i,0,n-1){
        cin >> cost[i];
    }
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<> > pq;// cost, node
    FOR(i,0,n-1){
        pq.emplace(cost[i],i);
    }
    ll node, curCost,childCost,childNode,totalSum;
    while(!pq.empty()){
        curCost = pq.top().first;
        node = pq.top().second;
        pq.pop();
        if(visited[node])continue;
        visited[node]=true;
        for(auto & i : transportation[node]){
            childNode = i.second;
            childCost = i.first;
            totalSum= curCost + childCost;
            if(totalSum < cost[childNode]){
                cost[childNode] = totalSum;
                pq.emplace(totalSum,childNode);
            }
        }
    }
    FOR(i,0,n-1){
        cout << cost[i] <<" ";
    }
    return 0;
}