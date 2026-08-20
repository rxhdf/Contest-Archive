#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    map<int, int> b;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        b[a[i]] = i;
    }
    for(int i = 1; i <= n; ++i){
        if(b[x - a[i]] > 0 && i != b[x - a[i]]){
            cout << i << " " << b[x - a[i]] << "\n";
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}