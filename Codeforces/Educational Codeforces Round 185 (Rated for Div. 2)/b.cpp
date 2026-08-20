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
        vector<int> a(n);
        set<int> s;
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            s.insert(a[i]);
        }
        cout << s.size() << "\n";
    }
    return 0;
}