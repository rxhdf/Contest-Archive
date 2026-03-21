#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n;
    vector<ll> a(n), b, pref1(n + 1, 0), pref2(n + 1, 0);
    for(auto &e: a){
        cin >> e;
    }
    cin >> m;
    b = a;
    sort(b.begin(), b.end());
    for(int i = 0; i < n; ++i){
        pref1[i + 1] = pref1[i] + a[i];
    }
    for(int i = 0; i < n; ++i){
        pref2[i + 1] = pref2[i] + b[i];
    }
    while(m--){
        int t, l, r;
        cin >> t >> l >> r;
        if(t == 1){
            cout << pref1[r] - pref1[l - 1] << "\n";
        }else{
            cout << pref2[r] - pref2[l - 1] << "\n";
        }
    }
    return 0;
}