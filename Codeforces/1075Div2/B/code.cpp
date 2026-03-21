#include <bits/stdc++.h>
#define int64 long long
#define i128 __int128_t
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

bool canReach(const vector<array<int64,3>>& jumps, int64 x, int64 R) {
    for (auto &j : jumps) {
        int64 a = j[0], b = j[1], c = j[2];

        i128 best = 0;

        for (int64 t : {R, R+1}) {
            if (t <= 0) continue;
            i128 k = (i128)t * b - 1;
            if (k <= 0) continue;
            i128 dist = k * a - (k / b) * c;
            best = max(best, dist);
        }

        if (best >= x) return true;
    }
    return false;
}

void run_case() {
    int n;
        int64 x;
        cin >> n >> x;

        vector<array<int64,3>> jumps(n);
        for (int i = 0; i < n; i++) {
            cin >> jumps[i][0] >> jumps[i][1] >> jumps[i][2];
        }

        int64 lo = 0, hi = (int64)1e18;
        int64 ans = -1;

        while (lo <= hi) {
            int64 mid = lo + (hi - lo) / 2;
            if (canReach(jumps, x, mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        cout << ans << '\n';
}

 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests = 1;
    cin >> tests;
    while (tests-- > 0)
        run_case();
}