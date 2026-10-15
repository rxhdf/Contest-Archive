// Source: https://usaco.guide/general/io

#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        vector<int> a(n), movs(n, 0);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            //cout << a[i] << " ";
        }   
        vector<int> b = a;
        sort(b.begin(), b.end());
        map<pair<int, int>, vector<int>> mp;
        for(int i = 0; i < n; ++i){
            if(a[i] != b[i]){
                mp[{a[i], b[i]}].push_back(i);
            }
        } 
        bool can = true;
        vector<pair<int, int>> ans;

        for(int i = 0; i < n; ++i){
            if(a[i] != b[i]){
                int x = a[i], y = b[i];
                if(mp[{x, y}].size() == mp[{y, x}].size()){
                    for(int j = 0; j < (int)mp[{x, y}].size(); ++j){
                        ans.push_back(make_pair(mp[{x, y}][j], mp[{y, x}][j]));
                        swap(a[mp[{x, y}][j]], a[mp[{y, x}][j]]);
                    }
                }else{
                    can = false;
                    break;
                }
            }
        }   
        if(can){
            cout << "SI\n" << ans.size() << "\n";
            for(auto e: ans){
                cout << e.first  + 1 << " " << e.second + 1 << "\n";
            }
        }else{
            cout << "No\n";
        }
    }
}
