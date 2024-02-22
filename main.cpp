#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5, P = 17;

int n, a[N], LOG[N];

void prepare() {
    for (int i = 2; i < N; ++i)
        LOG[i] = LOG[i / 2] + 1;
}

struct {
    int st[P][N];
    int operation(int lf, int rt) {
        return min(lf, rt);
    }
    void build() {
        for (int i = 0; i < n; ++i)
            st[0][i] = a[i];
        for (int p = 1; (1 << p) <= n; ++p) {
            for (int i = 0; i + (1 << p) <= n; ++i) {
                int x = st[p - 1][i];
                int y = st[p - 1][i + (1 << (p - 1))];
                st[p][i] = operation(x, y);
            }
        }
    }
    int operator()(int l, int r) {
        int p = LOG[r - l + 1];
        int x = st[p][l];
        int y = st[p][r - (1 << p) + 1];
        return operation(x, y);
    }
} st;

int main() {
    //ios::sync_with_stdio(false); cout.tie(nullptr); cin.tie(nullptr);
    prepare();
    int k,mx=-INT_MAX;
    cin >> n>>k;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        mx = max(mx,a[i]);
    }
    st.build();
    int mini = st(0,n-1);
    if(k==1)cout <<mini;
    else if(k==2){
        int ans=-INT_MAX;
        int l=0,r=0;
        while (r<n-1){
            mx = max(st(l,r),st(r+1,n-1));
            ans = max(ans,mx);
            ++r;
        }
        cout <<ans;
    }
    else cout << mx;
    return 0;
}

