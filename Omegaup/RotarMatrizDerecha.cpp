#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    iota(a.begin(), a.end(), 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    x %= n;
    rotate(a.rbegin(), a.rbegin() + x, a.rend());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
