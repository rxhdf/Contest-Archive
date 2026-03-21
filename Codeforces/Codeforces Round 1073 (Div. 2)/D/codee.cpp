#include <bits/stdc++.h>
#define ll long long
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

ll MOD = 998244353;
ll C[105][105];
ll dp[105][105][105]; // index-currentbalance-length

void binom() {
    // Precompute binomial coefficients
    for(int i = 0; i <= 100; i++){
        C[i][0] = 1;
        for(int j = 1; j <= i; j++){
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }
}

void run_case() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i <= n + 1; i++){
        for(int j = 0; j <= n + 1; j++){
            for(int l = 0; l <= n + 1; l++){
                dp[i][j][l] = 0;
            }
        }
    }

    dp[n][0][0] = 1;

    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j <= n; j++){
            for(int l = 0; l <= n - i; l++){
                ll res = dp[i + 1][j][l];
                if(l > 0) {
                    if(s[i] == '('){
                        if(j + 1 <= n){
                            res = (res + dp[i + 1][j + 1][l - 1]) % MOD;
                        }
                    }else{
                        if(j > 0){
                            res = (res + dp[i + 1][j - 1][l - 1]) % MOD;
                        }
                    }
                }
                dp[i][j][l] = res;
            }
        }
    }

    ll total_score = 0;
    for(int m = 1; m * 2 <= n; ++m){
        if (m < 2) continue;
        ll total_rbs = dp[0][0][2 * m];
        ll bad_rbs = 0;
        int open_cnt_prefix = 0; 

        for(int k = 0; k < n; ++k){
            if(s[k] == '('){
                if(m - 2 >= 0 && open_cnt_prefix >= m - 2){
                    ll ways_prefix = C[open_cnt_prefix][m - 2];
                    if(m - 1 <= n && m + 1 <= n){
                        ll ways_suffix = dp[k + 1][m - 1][m + 1];
                        ll combinations = (ways_prefix * ways_suffix) % MOD;
                        bad_rbs = (bad_rbs + combinations) % MOD;
                    }
                }
                open_cnt_prefix++;
            }
        }
        //good sequences
        ll good_rbs = (total_rbs - bad_rbs + MOD) % MOD;
        //score contriubtion
        ll score_val = (2 * m - 2);
        ll contribution = (good_rbs * score_val) % MOD;
        
        total_score = (total_score + contribution) % MOD;
    }

    cout << total_score << "\n";
}

 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    binom();
    int tests = 1;
    cin >> tests;
    while (tests-- > 0)
        run_case();
}