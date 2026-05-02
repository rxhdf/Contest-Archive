#include <bits/stdc++.h>
#include <ios>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> a(n);
    for(auto &e: a){
        cin >> e;
    }
    map<int, int> cnt;

    long long l = 0, ans = 0;
    for(int r = 0; r < n; ++r){
        cnt[a[r]]++;
        while(cnt[a[r]] >= 2){
            cnt[a[l]]--;
            ++l;
        }
        ans += (r - l + 1);
    }
    cout << ans << "\n";
    return 0;
}