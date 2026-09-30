// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int c, n;
void solve(){
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    int sum = 0;
    vector<int> reminders(c, -1);
    reminders[0] = 0;
    for(int i = 0; i < n; ++i){
        sum += a[i];
        int rem = (sum % c);
        if(reminders[rem] != -1){
            int start = reminders[rem] + 1;
            int ned = i + 1;
            for(int j = start; j <= ned; ++j){
                cout << j << " ";
            }
            cout << "\n";
            return;
        }else{
            reminders[rem] = i + 1;
        }
    }
}

int main() {
    while(cin >> c >> n && (c != 0 || n != 0)){
        solve();
    }
    return 0;
}
