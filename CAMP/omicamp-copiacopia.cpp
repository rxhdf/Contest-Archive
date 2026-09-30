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
        set<int> b;
        for(auto &e: a){
            cin >> e;
            b.insert(e);
        }
        cout << b.size() << "\n";
    }

    return 0;
}