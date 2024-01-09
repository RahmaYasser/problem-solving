// Codeforces 277A


#include <bits/stdc++.h>

using namespace std;

#define FOR(i,st,end) for(int i=st;i<=end;i++)
typedef long long ll;


class DSU{
public:int N;

    explicit DSU(int n):N(n){
        pr=vector<int>(N,-1);
        sz=vector<int>(N,1);
       // iota(pr.begin(), pr.end(),0);
    }

public:vector<int> pr;
public:vector<int> sz;
public:int parent(int node){
        if(pr[node]==-1)return -1;
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
    int n,m,x,node1,node2,ans=0;
    cin >>n >>m;
    m++;
    DSU* dsu = new DSU(m);
    for(int i=0;i<n;++i){
        cin >> x;
        if(x){
            cin >> node1;
            if(dsu->pr[node1]==-1)dsu->pr[node1] = node1;
            x--;
        }else ans++;
        while (x--){
            cin >> node2;
            if(dsu->pr[node2]==-1)dsu->pr[node2] = node2;
            dsu->connect(node1,node2);
            node1=node2;
        }
    }
    int i=1;
    while(i<m){
        x=dsu->parent(i);
        i++;
    }

    sort(dsu->pr.begin(),dsu->pr.end());
    node2=0;
    x=m;
    for(int i=1;i<m;i++){
        if(dsu->pr[i]!=-1){
            node1 = dsu->pr[i];
            x=i;
            break;
        }
    }
    for(int i=x+1;i<m;i++){
        if(dsu->pr[i]!=node1){
            node1=dsu->pr[i];
            ans++;
        }
    }
    cout <<ans;
    return 0;
}