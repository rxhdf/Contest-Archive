#include <bits/stdc++.h>
#include <cstdint>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    long long sum = 0, mn = INT32_MAX;
    for(auto &e: a){
        cin >> e;
        sum += e;
    }
    sort(a.begin(), a.end());
    long long k = sum / n;
    long long r = sum % n;
    long long ans = 0;
    for(int i = 0; i < n; ++i){
        if(i < n - r){
            ans += max(0LL, (k - a[i]));
        }else{
            ans += max(0LL, (k + 1) - a[i]);
        }
    }
    cout << ans << "\n";
    
    return 0;
}