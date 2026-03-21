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
    vector<bool> present(n + 1, false);
    bool has_one = false;

    vector<int> distinct_a;
    
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        if (val == 1) {
            has_one = true;
        } else {
            if (!present[val]) {
                present[val] = true;
                distinct_a.push_back(val);
            }
        }
    }
    
    sort(distinct_a.begin(), distinct_a.end());
    
    // minimo para obtener el producto
    vector<int> dp(n + 1, INT32_MAX);
    dp[1] = 0;
    
    for (int i = 1; i <= n; ++i) {
        //Revisar si se puede extender el estado
        if (dp[i] == INT32_MAX) continue;
        
        for (int v : distinct_a) {
            long long next_val = (long long)i * v;
            
            if (next_val > n) break;
            
            // Busca camino mas corto
            if (dp[next_val] > dp[i] + 1) {
                dp[next_val] = dp[i] + 1;
            }
        }
    }
    
    for (int k = 1; k <= n; ++k) {
        if (k == 1) {
            //caso especial
            if (has_one) cout << 1 << " ";
            else cout << -1 << " ";
        } else {
            if (dp[k] == INT32_MAX) cout << -1 << " ";
            else cout << dp[k] << " ";
        }
    }
    cout << "\n";
}

 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests = 1;
    cin >> tests;
    while (tests-- > 0)
        run_case();
}