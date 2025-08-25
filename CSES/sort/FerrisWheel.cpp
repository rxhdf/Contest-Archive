#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, X;
    cin >> N >> X;
    vector<int> weights(N);
    for (int i = 0; i < N; ++i) {
        cin >> weights[i];
    }
    sort(weights.begin(), weights.end());
    int ans = 0;
    int i = 0, j = N - 1;
    while (i <= j) {
        if (weights[i] + weights[j] <= X) {
            i++;
        }
        j--;
        ans++;
    }
    cout << ans << "\n";
    return 0;
}