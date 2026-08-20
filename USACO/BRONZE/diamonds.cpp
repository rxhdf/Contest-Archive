#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("diamond");
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int max_length = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i; j < n; ++j){
            if(a[j] - a[i] <= k)max_length = max(max_length, j - i + 1);
        }
    }
    cout << max_length << "\n";
    return 0;
}