#include <bits/stdc++.h>
#include <pthread.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(auto &e: a){
            cin >> e;
        }
        for(auto &e: b){
            cin >> e;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for(auto e: a){
            cout << e << " ";
        }
        cout << "\n";
        for(auto e: b){
            cout << e << " ";
        }
        cout << "\n";
    }

    return 0;
}