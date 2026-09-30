#include <bits/stdc++.h>

using namespace std;

vector<long long> p10;

int hazloGod(pair<int, int>& e){
    int i = 0;
    while(e.first > p10[i] && p10[i] - e.first <= e.first){
        ++i;
    }
    return p10[i] - e.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    long long power = 1;
    for(int i = 0; i < 63; ++i){
        p10.push_back(power);
        power *= 2;
    }
    while(tt--){
        int n;
        cin >> n;
        vector<pair<int, int>> a(n);
        vector<int> last;
        for(int i = 0; i < n; ++i){
            cin >> a[i].first;
            a[i].second = i;
            last.push_back(a[i].first);
        }
        sort(a.begin(), a.end());
        cout << n << "\n";
        for(int i = 0; i < n; ++i){
            int diff = hazloGod(a[i]);
            cout << a[i].second + 1 << " " << diff << "\n";
            last[a[i].second] += diff;
        }
        
    }

    return 0;
}