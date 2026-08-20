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
        vector<int> a(n);
        for (auto &x : a) cin >> x;

        vector<int> g(n, 0); // resultado para cada prefijo
        int cur_gcd = 0;
        int k = 0;

        for (int i = 0; i < n; ++i) {
            cur_gcd = (i == 0) ? a[i] : gcd(cur_gcd, a[i]);
            k = max(k, i); // podemos poner al menos todos los elementos hasta i
            g[i] = k;

            // Si GCD cambia, actualizamos k para reflejar el índice óptimo
            // En este enfoque incremental, g[i] se construye correctamente prefijo por prefijo
        }

        for (int i = 0; i < n; ++i) {
            cout << g[i] << (i + 1 == n ? '\n' : ' ');
        }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests = 1;
    cin >> tests;
    while (tests-- > 0)
        run_case();
}