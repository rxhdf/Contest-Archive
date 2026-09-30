#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(auto &e: a){
        cin >> e;
    }
    int l = 0, r = 0;
    long long sum = 0, ans = 0, cnt = 0;
    for(r = 0; r < n; ++r){
        sum += a[r];
        while(sum >= k){

            sum -= a[l];
            l++;
            cnt += n - r;
        }
    }
    cout << cnt << "\n";
 
    return 0;
}