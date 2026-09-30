#include <bits/stdc++.h>
#include <pthread.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(auto &e: a){
        cin >> e;
    }
    long long actual = 0;
    for(int i = 0; i < n; ++i){
        b[i] = a[i] / 2 + (a[i] % 2 != 0 ? (a[i] > 0 ? 1 : -1) : 0);;
        actual += b[i];
    }
    ///cout << actual << "\n";
    if(actual > 0){
        for(int i = 0; i < n; ++i){
            if(a[i] & 1 && actual > 0){
                b[i]--;
                actual--;
            }
        }
    }else{
        for(int i = 0; i < n; ++i){
            if(a[i] & 1 && actual < 0){
                b[i]++;
                actual++;
            }
        }
    }
    long long s = 0;
    for(auto e: b){
        cout << e << "\n";
        s += e;
    }
    return 0;
}