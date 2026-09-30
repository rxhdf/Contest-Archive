#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n, 0);
    map<int, int, greater<int>> times;
    int aux = 0, tim = 0;
    for(int i = 0; i < n; ++i){
        int e;
        cin >> e;
        times[e]++;
        aux = max(aux, e);
    }
    int index = 0;
    while(index < n && !times.empty()){
        tim = times.begin()->second;
        vector<int> te;
        for(auto &e: times){
            int ac = e.second;
            for(int i = 0; i < min(ac, tim); ++i){
                a[index] = e.first;
                index++;
                --e.second;
            }        
            if(e.second == 0){
                te.push_back(e.first);
            }
        }
        for(int i = 0; i < te.size(); ++i){
            times.erase(te[i]);
        }
        
    }
    for(int i = 0; i < n; ++i){
        cout << a[i] << " ";
    }
    cout << "\n";
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