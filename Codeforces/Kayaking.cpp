#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    int total_instability = 0;
    for(int i = 2; i <= n; ++i){
        int instability = INT32_MAX;
        for(int j = 2; j <= n; ++j){
            if(i == j)continue;
            if(abs(a[i] - a[j]) < instability){
                a[j] = a[i] = 0;
                instability = abs(a[i] - a[j]);
            }
        }
        total_instability += instability;
    }
    cout << total_instability << "\n";
    return 0;
}