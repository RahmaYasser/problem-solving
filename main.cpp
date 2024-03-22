#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class SparseTable{
    static const int N = 2e5 + 5,P=18;
public:int a[N];
public: int table[P][N];
private: int log[N];

private:static int operation(int a, int b,int op){
        if(op == 0)return max(a,b);
        else return min(a,b);
    }
public:void build (int n,int op){
        for(int i=0;i<n;i++){
            table[0][i] = a[i];
        }
        for(int p=1;(1<<p) <= n;p++){
            for(int i=0;i+(1<<p)-1 < n;i++){
                table[p][i] = operation(table[p-1][i], table[p-1][i+(1<<(p-1))],op);
            }
        }
        log[0] = 0;
        log[1] = 0;
        for(int i=2;i<N;i++){
            log[i] = log[i/2]+1;
        }
    }
public:int query(int l,int r,int op){
        int p = log[r-l+1];
        return operation(table[p][l], table[p][r - (1<<p) + 1],op);
    }
};


int main() {
    int t,n,q,l,r,x;cin>>t;
    SparseTable *miniSp = new SparseTable;
    SparseTable *maxSp = new SparseTable;
    while(t--){
        cin >>n>>q;
        string s;
        cin >>s;
        vector<int> prefixSum(n+1);
        prefixSum[0] = 0;
        x=0;
        for(int i=0;i<n;i++){
            if(s[i]=='+')x++;
            else x--;
            miniSp->a[i] = x;
            maxSp->a[i] = x;
            prefixSum[i+1] = x;
        }
        miniSp->build(n,1);
        maxSp->build(n,0);
        for(int i=0;i<q;++i){
            cin >>l>>r;
            if(r-l+1==n) cout <<'1'<<"\n";
            else{
                int sum=prefixSum[r]-prefixSum[l-1];
                int mini=INT_MAX,maxi=-INT_MAX;
                l--;r--;
                if(l>0){
                    mini = min(mini,miniSp->query(0,l-1,1));
                    maxi = max(maxi,maxSp->query(0,l-1,0));
                }
                if(r<n-1){
                    mini = min(mini,miniSp->query(r+1,n-1,1)-sum);
                    maxi = max(maxi,maxSp->query(r+1,n-1,0)-sum);
                }
                int ans;
                if(maxi >= 0 && mini <= 0){
                    ans = maxi-mini+1;
                }else ans = maxi-mini+2;
                cout <<ans<<"\n";
            }
        }
    }
    return 0;
}

