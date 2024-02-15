#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 6, P1 = 29, MOD1 = 1e9 + 7, P2 = 31, MOD2 = 1e9 + 9;

int inv_p1[N], inv_p2[N];

int sub(int a, int b, int mod) {
    a -= b;
    if (a < 0)
        a += mod;
    return a;
}

int add(int a, int b, int mod) {
    return (a + b) % mod;
}

int mul(int a, int b, int mod) {
    return 1ll * a * b % mod;
}

int power(int b, int p, int mod) {
    int ans = 1;
    for (; p; p /= 2) {
        if (p & 1)
            ans = mul(ans, b, mod);
        b = mul(b, b, mod);
    }
    return ans;
}

struct Hash {
    vector<pair<int, int>> prf;
    Hash(const string &s) {
        int p1 = 1, h1 = 0, p2 = 1, h2 = 0;
        for (char c : s) {
            int i = c - 'a' + 1;
            h1 = add(h1, mul(i, p1, MOD1), MOD1);
            h2 = add(h2, mul(i, p2, MOD2), MOD2);
            p1 = mul(p1, P1, MOD1);
            p2 = mul(p2, P2, MOD2);
            prf.emplace_back(h1, h2);
        }
    }
    pair<int, int> operator()(int l, int r) {
        auto [h1, h2] = prf[r];
        if (l > 0) {
            auto [sh1, sh2] = prf[l - 1];
            h1 = sub(h1, sh1, MOD1);
            h2 = sub(h2, sh2, MOD2);
            h1 = mul(h1, inv_p1[l], MOD1);
            h2 = mul(h2, inv_p2[l], MOD2);
        }
        return {h1, h2};
    }
    static void prepare() {
        inv_p1[N - 1] = power(power(P1, N - 1, MOD1), MOD1 - 2, MOD1);
        inv_p2[N - 1] = power(power(P2, N - 1, MOD2), MOD2 - 2, MOD2);
        for (int i = N - 2; i >= 0; --i) {
            inv_p1[i] = mul(inv_p1[i + 1], P1, MOD1);
            inv_p2[i] = mul(inv_p2[i + 1], P2, MOD2);
        }
    }
};

int main() {
    ios::sync_with_stdio(false); cout.tie(nullptr); cin.tie(nullptr);
    Hash::prepare();
    int tc; cin >> tc;
    while (tc--) {
        int n, k; string s;
        cin >> n >> k >> s;
        set<pair<int, int>> st;
        Hash sh = s;
        for (int i = 0; i + k <= s.size(); ++i)
            st.insert(sh(i, i + k - 1));
        cout << st.size() << '\n';
    }
    return 0;
}