#include <bits/stdc++.h>
#include <iterator>

using namespace std;
using ll = long long;

vector<ll> prefix_sum;

bool can(ll l, ll r, ll target_sum){
    if(l == r){
        return prefix_sum[l] - (l > 0 ? prefix_sum[l - 1] : 0) == target_sum;
    }
    ll mitad1 = (target_sum + 1) / 2;
    ll mitad2 = target_sum - mitad1;
    ll lookingFor = mitad1 + (l > 0 ? prefix_sum[l - 1] : 0);
    auto itr = lower_bound(prefix_sum.begin() + l, prefix_sum.begin() + r + 1, lookingFor);
    if(itr == prefix_sum.begin() + r + 1 || *itr != lookingFor){
        return false;
    }
    ll pos = distance(prefix_sum.begin(), itr);
    if(pos == r)return false;

    return can(l, pos, mitad1) && can(pos + 1, r, mitad2);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> a(n);
    for(auto &x: a){
        cin >> x;
    }
    for(int i  = 0; i < n; ++i){
        prefix_sum.push_back(a[i] + (i > 0? prefix_sum[i - 1] : 0));
    }
    bool ans = can(0, n - 1, prefix_sum[n - 1]);

    if(ans){
        cout << "Si\n";
    }else{
        cout << "No\n";
    }
    return 0;
}