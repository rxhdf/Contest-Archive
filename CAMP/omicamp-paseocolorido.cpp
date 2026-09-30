#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &e: a){
        cin >> e;
    }
    long long ans = 0;
    for(long long i = 0; i < n; ++i){
        if(a[i] != a[0]){
            ans = max(ans, i);
        }
        if(a[i] != a[n - 1]){
            ans = max(ans, abs(n - i - 1));
        }
    }
    cout << ans << "\n";
    return 0;
}

