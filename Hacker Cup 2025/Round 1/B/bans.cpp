#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(nullptr); 
    //freopen((s + ".in").c_str(), "r", stdin);
    //freopen((s + ".out").c_str(), "w", stdout);
}

bool valid(ll h, const vector<ll>& a){
    int n = a.size();
    int i = 0;
    while(i < n){
        int j = i;
        ll min_val = a[i];
        while(j < n){
            min_val = min(min_val, a[j]);
            if(j < n - 1 && abs(a[j] - a[j+1]) > h){
                break;
            }
            j++;
        }
        if(min_val > h){
            return false;
        }
        i = j + 1;
    }
    return true;
}
int main() {
    setIO("");
    int tt, i = 1;
    cin >> tt;
    while(i <= tt){
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i){
            cin >> a[i];
        }
        ll lo = 0, hi = *max_element(a.begin(), a.end());
        while(lo < hi){
            ll mid = (lo + hi) / 2;
            if(valid(mid, a)){
                hi = mid;
            } else{
                lo = mid + 1;
            }
        }
        cout << "Case #" << i << ": " << lo << "\n";
        ++i;
    }
    return 0;
}