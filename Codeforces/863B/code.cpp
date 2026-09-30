#include <bits/stdc++.h>
#include <cstdint>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int lm = 2 * n;
    vector<int> a(lm);
    for(int i = 0; i  < lm; ++i){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    set<pair<int, int>> pairs;
    int ans = INT32_MAX;
    for(int i = 0; i < lm; ++i){
        for(int j = 0; j < lm; ++j){
            if(i != j && (pairs.find({i, j}) == pairs.end() && pairs.find({j, i}) == pairs.end())){
                pairs.insert({i, j});
                if(i > j)swap(i, j);
                vector<int> b;
                for(int h = 0; h < lm; ++h){
                    if(h == i || h == j)continue;
                    b.push_back(a[h]);
                }
                int aux = 0;
                for(int h = 0; h < b.size() - 1; h+=2){
                    aux += abs(b[h] - b[h + 1]);
                }
                ans = min(aux, ans);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}