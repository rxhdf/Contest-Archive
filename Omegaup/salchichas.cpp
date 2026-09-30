#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for(auto&e:a)cin>>e;
    sort(a.begin(), a.end());
    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(s - a[i] >= 0){
            ans++;
            s -= a[i];
        }else{
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}