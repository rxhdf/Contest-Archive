#include <bits/stdc++.h>
#include <cstdint>
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
    vector<pair<char, int>> cows(n);
    for(int i = 0; i < n; ++i){
        cin >> cows[i].first >> cows[i].second;
    }
    sort(cows.begin(), cows.end());

    int ans = INT32_MAX;
    for(int i = 0; i < n; ++i){
        int liars = 0;
        for(int j = 0; j < n; ++j){
            if(i == j)continue;
            if(cows[i].second > cows[j].second && cows[j].first == 'L')liars++;
            if(cows[i].second < cows[j].second && cows[j].first == 'G')liars++;
        }
        ans = min(ans, liars);
    }
    cout << ans << "\n";
    return 0;
}