#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        vector<pair<int, int>> v(n);
        vector<int> ans(n);
        for(int i = 0; i < n; ++i){
            cin >> v[i].first;
        }
        for(int i = 0; i < n; ++i){
            cin >> v[i].second;
        }
          
    }
    return 0;
}