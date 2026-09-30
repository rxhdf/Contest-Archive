#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    
    ll A = (k + 1) / 2;
    ll B = k / 2;
    ll C = A - B;
    
    vector<ll> P(n + 1);
    P[0] = 0;
    for (int i = 1; i <= n; i++) {
        P[i] = P[i - 1] + a[i - 1];
    }
    
    vector<int> L(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && b[st.top()] <= b[i]) {
            st.pop();
        }
        if (!st.empty()) {
            L[i] = st.top();
        }
        st.push(i);
    }
    
    int logn = 0;
    while ((1 << logn) <= n + 1) logn++;
    vector<vector<ll>> st_table(logn, vector<ll>(n + 1));
    for (int i = 0; i <= n; i++) {
        st_table[0][i] = P[i];
    }
    for (int i = 1; i < logn; i++) {
        for (int j = 0; j + (1 << i) <= n + 1; j++) {
            st_table[i][j] = min(st_table[i - 1][j], st_table[i - 1][j + (1 << (i - 1))]);
        }
    }
    
    auto rmq = [&](int l, int r) {
        if (l > r) return INF;
        int len = r - l + 1;
        int i = 0;
        while ((1 << (i + 1)) <= len) i++;
        return min(st_table[i][l], st_table[i][r - (1 << i) + 1]);
    };
    
    vector<ll> F(n, -INF);
    ll ans = -INF;
    for (int j = 0; j < n; j++) {
        int low = L[j] + 1;
        int high = j;
        ll min_val = rmq(low, high);
        ll candidate1 = C * b[j] - min_val;
        ll candidate2 = (L[j] >= 0) ? F[L[j]] : -INF;
        F[j] = max(candidate1, candidate2);
        ans = max(ans, P[j + 1] + F[j]);
    }
    
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}