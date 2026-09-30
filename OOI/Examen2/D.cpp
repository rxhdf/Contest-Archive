#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#define ll unsigned long long
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

ll catalan_numbers(ll n){
    vector<ll> C(n + 1, 0);
    C[0] = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < i; ++j){
            C[i] += C[j] * C[i - 1 - j];
        }
    }
    return C[n];
}

int main() {
    int n;
    cin >> n;
    cout << catalan_numbers(n - 2) << "\n";
    return 0;

}