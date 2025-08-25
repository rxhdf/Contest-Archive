#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<pair<int, int>> points(N);
    for(int i = 0; i < N; ++i){
        cin >> points[i].first;
    }
    for(int i = 0; i < N; ++i){
        cin >> points[i].second;
    }
    int ans = 0;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            int dx = points[i].first - points[j].first;
            int dy = points[i].second - points[j].second;
            int ds = dx * dx + dy *dy;
            ans = max(ans, ds);
        }
    }
    cout << ans << "\n";
    return 0;
}