#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;

    while(tt--){
        vector<pair<int, int>> vert(3);
        for(int i = 0; i < 3; ++i){
            cin >> vert[i].first >> vert[i].second;
        }
        long long ans = 0;
        for(int i = 0; i < 3; ++i){
            int j = (i + 1) % 3;
            int k = (j + 1) % 3;

            auto [x1, y1] = vert[i];
            auto [x2, y2] = vert[j];
            auto [x3, y3] = vert[k];

            if(y1 == y2 && y1 > 0 && y3 < y1){
                ans = abs(x1 - x2);
            }
        }
        cout << ans << "\n";
    }

    return 0;
}