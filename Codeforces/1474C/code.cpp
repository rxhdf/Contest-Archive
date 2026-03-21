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
    vector<int> a(2 * n);
    
    for(int i = 0; i < 2 * n; ++i){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    auto check = [](int x,vector<int> &a){
        multiset<int> st;
        for(auto e: a){
            st.insert(e);
        }
        vector<int> ns;
        bool ok = true;
        for(int i = 0; i < (a.size() / 2); ++i){
            auto ft = prev(st.end());
            int y = x - *ft;
            st.erase(ft);
            auto itr2 = st.find(y);
            if(itr2 == st.end()){
                ok = false;
                break;
            }
            st.erase(itr2);
            ns.push_back(x - y);
            ns.push_back(y);
            x = max(y, x - y);
        }
        if(!ok){
            return ns = {};
        }
        return ns;
    };
    for(int i = 0; i < 2 * n; ++i){
        vector<int> ans = check(a[i] + a[(2 * n) - 1], a);
        if(ans.size()){ 
            cout << "YES\n";
            cout << a[i] + a[(2 * n) - 1] << "\n";
            for(int j = 0; j < 2 * n - 1; j += 2){
                cout << ans[j] << " " << ans[j + 1] << "\n";
            }
            return;
        }
    }
    cout << "NO\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests = 1;
    cin >> tests;
    while (tests-- > 0)
        run_case();
}