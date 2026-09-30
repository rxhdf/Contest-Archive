#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n), diferences(n, 0), prefix(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 1; i < n; ++i){
        diferences[i] = a[i] - a[i - 1];
    }
    prefix[0] = diferences[0];
    for(int i = 1; i < n; ++i){
        prefix[i] = prefix[i - 1] + diferences[i];
    }
    int ans = INT32_MIN;
    for(int i = 0; i <= n - k; ++i){
        int emotion = prefix[i + k - 1] - prefix[i];
        ans = max(ans, emotion);
    }
    cout << ans << "\n";
    return 0;
}