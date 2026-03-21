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
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<long long> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    
    vector<long long> c(m);
    for (int i = 0; i < m; ++i) {
        cin >> c[i];
    }
    
    sort(a.begin(), a.end());
    
    vector<pair<long long, long long>> monsters;
    for (int i = 0; i < m; ++i) {
        monsters.push_back({b[i], c[i]});
    }
    
    sort(monsters.begin(), monsters.end(), [](const pair<long long, long long>& p1, const pair<long long, long long>& p2) {
        if (p1.first != p2.first) {
            return p1.first < p2.first;
        }
        return p1.second > p2.second;
    });
    
    multiset<long long> swords;
    for (long long x : a) {
        swords.insert(x);
    }
    
    int kills = 0;
    
    for (auto& monster : monsters) {
        long long b_val = monster.first;
        long long c_val = monster.second;
        
        while (!swords.empty() && *swords.begin() < b_val) {
            swords.erase(swords.begin());
        }
        
        if (swords.empty()) {
            break;
        }
        
        auto it = swords.lower_bound(b_val);
        if (it == swords.end()) {
            continue;
        }
        
        long long sword_damage = *it;
        swords.erase(it);
        
        if (c_val > 0) {
            swords.insert(max(sword_damage, c_val));
        }
        
        kills++;
    }
    
    cout << kills << '\n';
}

 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests = 1;
    cin >> tests;
    while (tests-- > 0)
        run_case();
}