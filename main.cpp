// Codeforces 939D


#include <bits/stdc++.h>

using namespace std;

#define FOR(i,st,end) for(int i=st;i<=end;i++)
typedef long long ll;


class DSU{
public:int N=26;

    explicit DSU() {
        pr=vector<int>(N);
        sz=vector<int>(N,1);
        iota(pr.begin(), pr.end(),0);
    }

public:vector<int> pr;
public:vector<int> sz;
private:int parent(int node){
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
    int n;
    cin >>n;
    DSU* dsu = new DSU();
    string s1,s2;
    cin >>s1>>s2;
    vector<pair<char,char>> res;
    for(int i=0;i<s1.size();++i){
        if(!dsu->connected(s1[i]-'a',s2[i]-'a')){
            dsu->connect(s1[i]-'a',s2[i]-'a');
            res.emplace_back(s1[i],s2[i]);
        }
    }
    cout <<res.size()<<"\n";
    for(auto p: res){
        cout <<p.first <<" "<<p.second<<"\n";
    }

    return 0;
}