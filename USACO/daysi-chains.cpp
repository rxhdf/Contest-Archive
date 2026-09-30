#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &e: a){
        cin >> e;
    }
    int ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            float average = 0;
            map<float, int> visited;
            for(int k = i; k <= j; ++k){
                
                average += a[k];
                visited[a[k]]++;
            }
            if(visited[(float)(average / (abs(i - j) + 1))])ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}