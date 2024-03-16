// A - Potentiometers
#include <bits/stdc++.h>

using namespace std;
using ll = long long;




class SparseTable{
    static const int N = 1e5 + 5,P=17;
    public:int a[N];
    public: int table[P][N];
private: int log[N];

    private:static int operation(int a, int b){
        return min(a,b);
    }
public:void build (int n){
        for(int i=0;i<n;i++){
            table[0][i] = a[i];
        }
        for(int p=1;(1<<p) <= n;p++){
            for(int i=0;i+(1<<p)-1 < n;i++){
                table[p][i] = operation(table[p-1][i], table[p-1][i+(1<<(p-1))]);
            }
        }
        log[0] = 0;
        log[1] = 0;
        for(int i=2;i<N;i++){
            log[i] = log[i/2]+1;
        }
    }
public:int query(int l,int r){
        int p = log[r-l+1];
        return min(table[p][l], table[p][r - (1<<p) + 1]);
    }
};


int main() {
    int n,l,r; cin >>n;
    SparseTable *st=new SparseTable;
    for(int i=0;i<n;i++)cin >> st->a[i];
    st->build(n);
    int q;cin>>q;
    for(int i=0;i<q;i++){
        cin >>l>>r;
        cout <<st->query(l,r)<<"\n";
    }
    return 0;
}

