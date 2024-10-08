#include <bits/stdc++.h>

using namespace std;

unsigned long long int combination(int n, int k) {
    return (n * (n - 1)) / 2;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    long long int P = N / M;
    long long int DB = N % M;
    long long int minx = 0;

    if (DB != 0) {
        minx += DB * combination(P + 1, 2);
        minx += (M - DB) * combination(P, 2);
    } else {
        minx = M * (combination(P, 2));
    }
    cout << minx << " " << combination((N - M) + 1, 2) << "\n";

    return 0;
}