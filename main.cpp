#include <bits/stdc++.h>

using namespace std;

#define FOR(i,st,end) for(int i=st;i<=end;i++)
typedef long long ll;

const int N=100;
int pr[N];
int sz[N];

void init(){
    iota(pr, pr+N,0);
    iota(sz,sz+N,1);
}
int parent(int node){
    if(node==pr[node])return node;
    return pr[node]=parent(pr[node]);
}
void connect(int node1,int node2){
    node1=parent(node1);
    node2=parent(node2);
    if(node1==node2) return;
    if(sz[node2] > sz[node1]){ // small to large, merge small tree to large tree
        swap(node1,node2);
    }
    sz[node1] += sz[node2];
    pr[node2]=node1; // node2 is the child
}

bool connected(int node1, int node2){
    return parent(node1)== parent(node2);
}

int main() {

    return 0;
}