// Codeforces 1559D1


#include <bits/stdc++.h>

using namespace std;

#define FOR(i,st,end) for(int i=st;i<=end;i++)
typedef long long ll;


class DSU{
public:int N;

    explicit DSU(int n):N(n){
        pr=vector<int> (n);
        sz=vector<int> (n);
        iota(pr.begin(), pr.end(),0);
        iota(sz.begin(), sz.end(),1);
    }

public:vector<int> pr;
public:vector<int> sz;
public:int parent(int node){
        if(node==pr[node])return node;
        return pr[node]=parent(pr[node]);
    }
public:void connect(int node1,int node2){
        node1=parent(node1);
        node2=parent(node2);
        if(node1==node2) return;
        if(sz[node2] > sz[node1]){ // small to large, merge small tree to large tree
            swap(node1,node2);
        }
        sz[node1] += sz[node2];
        pr[node2]=node1; // node2 is the child
    }

public:bool connected(int node1, int node2){
        return parent(node1)== parent(node2);
    }
};



int main() {
    int n,m1,m2,u,v;
    cin >>n>>m1>>m2;
    DSU *dsu1= new DSU(n+1);
    DSU *dsu2= new DSU(n+1);
    FOR(i,1,m1){
        cin >> u>>v;
        dsu1->connect(u,v);
    }
    FOR(i,1,m2){
        cin >> u>>v;
        dsu2->connect(u,v);
    }
    vector<pair<int,int>> ans;
    FOR(i,1,n){
        FOR(j,i+1,n){
            if(!dsu1->connected(i,j) && !dsu2->connected(i,j)){
                dsu1->connect(i,j);
                dsu2->connect(i,j);
                ans.emplace_back(i,j);
            }
        }
    }
    cout << ans.size()<<"\n";
    for(auto pr : ans){
        cout <<pr.first <<" "<<pr.second <<"\n";
    }
    return 0;
}