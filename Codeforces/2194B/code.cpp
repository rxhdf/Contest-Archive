#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    long long ans = 0;
    for(auto &e: a)cin >> e;
    sort(a.begin(), a.end());
    bool state = false;
    int i = 0, j = n - 1;
    while(i < j){
        if(state){
            //usar el mas chico
            a[j] += (a[i] / x) * y;
            state = false;
            --j;
        }else{
            //usar el mas grande
            a[i] += (a[j] / x) * y;
            state = true;
            ++i;
        }
    }
    cout << *max_element(a.begin(), a.end()) << "\n";
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