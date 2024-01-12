// Codeforces 25D


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
        return parent(pr[node]);
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
    int n,x,y;cin >>n;
    DSU *dsu= new DSU(n+1);
    vector<pair<int,int>>closed;
    vector<pair<int,int>>open;
    FOR(i,1,n-1){
        cin >>x>>y;
        if(!dsu->connected(x,y)){
            dsu->connect(x,y);
        }else{
            closed.emplace_back(x,y);
        }
    }
    FOR(i,1,n){
        FOR(j,i+1,n){
            if(!dsu->connected(i,j) ){
                dsu->connect(i,j);
                open.emplace_back(i,j);
            }
        }
    }
    n=open.size();
    cout << n <<"\n";
    FOR(i,0,n-1){
        cout << closed[i].first <<" " << closed[i].second <<" "<<  open[i].first <<" " << open[i].second << "\n";
    }

    return 0;
}