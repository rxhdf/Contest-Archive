#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> p(n);
        for(auto &e: p){
            cin >> e;
        }
        reverse(p.begin(), p.end());
        for(auto e: p){
            cout << e << " ";
        }
        cout << "\n";
    }

    return 0;
}