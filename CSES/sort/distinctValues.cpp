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
    sort(a.begin(), a.end());
    int ans = 1;
    for(int i = 0; i < n - 1; ++i){
        if(a[i] != a[i + 1])ans++;
    }
    cout << ans << "\n";
    return 0;
}