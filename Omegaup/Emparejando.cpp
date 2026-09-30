#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> a(4);
    for(int i = 0; i < 4; ++i){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    cout << abs((a[0] + a[3]) - (a[1] + a[2])) << "\n";
    return 0;
}