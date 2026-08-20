#include <bits/stdc++.h>
using namespace std;
 
// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
 
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename... Args> ostream& operator<<(ostream& os, const tuple<Args...>& t) { os << '('; apply([&os](const Args&... args) { size_t n = 0; ((os << args << (++n != sizeof...(Args) ? ", " : "")), ...); }, t); return os << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void run_case() {
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    int maxk = 0;
    for (int i = 0; i < n; ++i) {
        int k; cin >> k;
        a[i].resize(k);
        for (int j = 0; j < k; ++j) cin >> a[i][j];
        maxk = max(maxk, k);
    }
    int pos = 0;
    vector<int> bottom; bottom.reserve(maxk);
    while (pos < maxk) {
        vector<int> cand;
        cand.reserve(n);
        for (int i = 0; i < n; ++i) if ((int)a[i].size() > pos) cand.push_back(i);
        auto cmp_suffix = [&](int i, int j)->bool {
            int si = (int)a[i].size();
            int sj = (int)a[j].size();
            int p = pos;
            while (p < si && p < sj) {
                if (a[i][p] != a[j][p]) return a[i][p] < a[j][p];
                ++p;
            }
            return si < sj;
        };
        int best = cand[0];
        for (int idx = 1; idx < (int)cand.size(); ++idx) {
            int cur = cand[idx];
            if (cmp_suffix(cur, best)) best = cur;
        }
        for (int k = pos; k < (int)a[best].size(); ++k) bottom.push_back(a[best][k]);
        pos = (int)bottom.size();
    }
    for (int i = 0; i < (int)bottom.size(); ++i) {
        if (i) cout << ' ';
        cout << bottom[i];
    }
    cout << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests = 1;
    cin >> tests;
    while (tests-- > 0)
        run_case();
}