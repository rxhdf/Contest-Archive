#include <bits/stdc++.h>
#include <cstdint>

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<long long> a(n);

    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    long long k = 0;
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i] > a[i + 1]) {
            k = max(k, a[i] - a[i + 1]);
        }
    }

    if (k == 0) {
        cout << "Yes\n";
        return;
    }

    int descents_in_block = 0;

    for (int i = 0; i + 1 < n; ++i) {
        if (a[i] > a[i + 1]) {
            ++descents_in_block;
        }

        if (a[i + 1] - a[i] >= k) {
            descents_in_block = 0;
        }

        if (descents_in_block >= 2) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while(tt--){
        solve();
    }

    return 0;
}