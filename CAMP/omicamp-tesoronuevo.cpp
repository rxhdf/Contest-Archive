#include <bits/stdc++.h>
#include <ios>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n), b(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i].first >> a[i].second;
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i].first >> b[i].second;
    }
    
    pair<int, int> ans;
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    ans = {a[0].first + b[0].first, b[0].second + a[0].second};
    cout << ans.first << " " << ans.second << "\n";
    return 0;
}