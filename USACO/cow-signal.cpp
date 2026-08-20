#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("cowsignal");
    int m, n, k;
    cin >> m >> n >> k;
    vector<string> st;
    for(int i = 0; i < m; ++i){
        string aux;
        for(int j = 0; j < n; ++j){
            char a;
            cin >> a;
            for(int l = 0; l < k; ++l){
                aux += a;
            }
        }
        st.push_back(aux);
    }
    for(int i = 0; i < st.size(); ++i){
        for(int j = 0; j < k; ++j){
            cout << st[i] << "\n";
        }
    }
    return 0;
}