#include <bits/stdc++.h>

using namespace std;

#define FOR(i,st,end) for(int i=st;i<=end;i++)
typedef long long ll;

const int N=100;
int pr[N];

void init(){
    iota(pr, pr+N,0);
}
int parent(int node){
    if(node==pr[node])return node;
    return parent(pr[node]);
}
void connect(int node1,int node2){
    node1=parent(node1);
    node2=parent(node2);
    if(node1==node2) return;
    pr[node1]=node2; // node1 is the child
}

bool connected(int node1, int node2){
    return parent(node1)== parent(node2);
}

int main() {

    return 0;
}