#include <bits/stdc++.h>
using namespace std;


class TreeAncestor {
public:
    int up[16][50004];
    TreeAncestor(int n, vector<int>& parent) {
        for(int i=0;i<n;i++) up[0][i] = parent[i];
        for(int p=1;p<16;p++){
            for(int i=0;i<n;i++){
                if(~up[p-1][i]){
                    up[p][i] = up[p-1][up[p-1][i]];
                }else{
                    up[p][i]=-1;
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int p = 0; p < 16; ++p) {
            if((k>>p) & 1){
                node = up[p][node];
                if(node == -1) return -1;
            }
        }
        return node;
    }
};

int main(){
    int n;cin >>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>> v[i];
    }
    TreeAncestor *t = new TreeAncestor(n,v);
    t->getKthAncestor(5,1);



    return 0;
}
