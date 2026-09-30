#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    map<string, string> mp;
    set<string> xd;
    for(int i = 1; i < n; ++i){
        string a, b;
        cin >> a >> b;
        mp[a] = b; 
        xd.insert(b);
        xd.insert(a); 
    }
    string start;
    for(auto [in, nxt]: mp){
        xd.erase(nxt);
    }
    start = *xd.begin();
    vector<string> ans;
    ans.emplace_back(start);
    for(int i = 1; i < n; ++i){
        ans.emplace_back(mp[start]);
        start = mp[start];
    }
    for(int i = ans.size() - 1; i >= 0; --i){
        cout << ans[i] << '\n';
    }
    return 0;
}