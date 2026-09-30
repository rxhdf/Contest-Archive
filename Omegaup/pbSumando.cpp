#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> ans(n, 0);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            int x;
            cin >> x;
            ans[j] += x;
        }
    }
    for(auto e: ans)cout << e << " ";
    
    return 0;
}