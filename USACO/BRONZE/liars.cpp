#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, char>> cows;
    for(int i = 0; i < n; ++i){
        char c;
        int p;
        cin >> c >> p;
        cows.push_back(make_pair(p, c));
    }
    sort(cows.begin(), cows.end());
    vector<int> rigth(n), left(n);
    for(int i = 1; i < n; ++i){
        left[i] += left[i - 1];
        if(cows[i - 1].second == 'L')left[i]++;
    }
    for(int i = n - 2; i >= 0; --i){
        rigth[i] += rigth[i + 1];
        if(cows[i + 1].second == 'G')rigth[i]++;
    }
    int ans = n;
    for(int i = 0; i < n; ++i){
        ans = min(ans, left[i] + rigth[i]);
    }
    cout << ans << "\n";
    return 0;
}