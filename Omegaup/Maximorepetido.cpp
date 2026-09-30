#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, mx = 0;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for(auto&e:a){
        cin >> e;
        mp[e]++;
        mx = max(e, mx);
    }
    cout << mp[mx] << "\n";
    return 0;
}