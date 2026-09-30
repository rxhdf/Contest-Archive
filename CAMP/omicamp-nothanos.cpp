#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int>a(2 * n);
    long long s = 0;
    for(auto &e: a){
        cin >> e;
        s += e;
    }
    long long s1 = 0;
    sort(a.begin(), a.end());
    for(int i = 0; i < n; ++i){
        s1 += a[i];
    }
    if(s1 != (s - s1)){
        for(auto e: a){
            cout << e << " ";
        }
        cout << "\n";
    }else{
        cout << "-1";
    }
    return 0;
}