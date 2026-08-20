#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &e: a){
        cin >> e;
    }
    int ans = INT32_MAX;
    for(int i = -1; i <= 1; ++i){
        for(int j = -1; j <= 1; ++j){
            int operations = abs(i) + abs(j), first = a[0] + i, second = a[1] + j;
            bool ok = true;
            for(int k = 2; k < n; ++k){
                
            }
        }
    }
    if(ans == INT32_MAX){
        cout << "-1\n";
    }else{
        cout << ans << "\n";
    }
    return 0;
}