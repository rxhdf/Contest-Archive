#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), prefix(n + 1);
    for(auto &e: a){
        cin >> e;
    }
    sort(a.begin(), a.end());
    for(int i = 1; i <= n; ++i){
        prefix[i] = prefix[i - 1] + a[i - 1];
    }
    ll mxSize = 0, cant = 0, j = 0;
    for(int i = 0; i < n; ++i){
        ll length = i - j + 1;
        ll cost = length * a[i] - (prefix[i + 1] - prefix[j]);
        while(cost > k){
            j++;
            length--;
            cost = length * a[i] - (prefix[i + 1] - prefix[j]);
        }
        if(length > mxSize){
            mxSize = length;
            cant = a[i];
        }
    }
    cout << mxSize << " " << cant << "\n";
    return 0;
}
