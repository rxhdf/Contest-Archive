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

const ll MOD = 1e9 + 7;

ll dist(ll a, ll b) {
    return (a > b) ? (a - b) : (b - a);
}

void run_case() {
    ll n, Ax, Ay, Bx, By;
    cin >> n >> Ax >> Ay >> Bx >> By;

    vector<pair<ll, ll>> houses(n);
    for (int i = 0; i < n; ++i) cin >> houses[i].first;
    for (int i = 0; i < n; ++i) cin >> houses[i].second;

    sort(houses.begin(), houses.end());

    vector<pair<ll, ll>> ranges;
    if (n > 0) {
        ll curX = houses[0].first;
        ll curMinY = houses[0].second;
        ll curMaxY = houses[0].second;

        for (int i = 1; i < n; ++i) {
            if (houses[i].first == curX) {
                curMinY = min(curMinY, houses[i].second);
                curMaxY = max(curMaxY, houses[i].second);
            } else {
                ranges.push_back({curMinY, curMaxY});
                curX = houses[i].first;
                curMinY = houses[i].second;
                curMaxY = houses[i].second;
            }
        }
        ranges.push_back({curMinY, curMaxY});
    }

    ll dpL = 0, dpR = 0;
    ll lastL = Ay, lastR = Ay;

    for (auto const& range : ranges) {
        ll L = range.first;
        ll R = range.second;
        ll len = R - L;

        ll nextL = min(dpL + dist(lastL, R), dpR + dist(lastR, R)) + len;
        ll nextR = min(dpL + dist(lastL, L), dpR + dist(lastR, L)) + len;

        dpL = nextL;
        dpR = nextR;
        lastL = L;
        lastR = R;
    }

    ll total_v = min(dpL + dist(lastL, By), dpR + dist(lastR, By));
    
    ll total_x = Bx - Ax;
    ll total_time = total_x + total_v;

    cout << total_time % MOD << "\n";
}

 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests = 1;
    cin >> tests;
    while (tests-- > 0)
        run_case();
}