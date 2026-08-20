#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> b(n);
        map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            mp[b[i]].push_back(i);
        }
        bool ok = true;
        for (auto &[k, v] : mp) {
            if (v.size() % k != 0) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << -1 << '\n';
            continue;
        }
        vector<int> ans(n, 0);
        int next = 1;
        for (auto &[k, v] : mp) {
            int m = v.size();
            for (int j = 0; j < m; j += k) {
                for (int i = 0; i < k; ++i) {
                    ans[v[j + i]] = next;
                }
                next++;
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}