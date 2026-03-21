#include <bits/stdc++.h>
using namespace std;

long long count_pairs(const vector<int>& a, int limit) {
    int l = 0, r = (int)a.size() - 1;
    long long ans = 0;
    while (l < r) {
        if (a[l] + a[r] <= limit) {
            ans += (r - l);
            l++;
        } else {
            r--;
        }
    }
    return ans;
}

void run_case() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    for (int &v : a) cin >> v;

    sort(a.begin(), a.end());

    long long ans1 = count_pairs(a, y);
    long long ans2 = count_pairs(a, x - 1);

    cout << ans1 - ans2 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) run_case();
}
