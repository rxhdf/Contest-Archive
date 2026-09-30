#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int A = 1, B = 0, C = 0;
    for (int d = 0; d < n; d++) {
        int newA = A * 2 + B * 2 + C * 0;
        int newB = A * 3 + B * 1 + C * 1;
        int newC = A * 1 + B * 2 + C * 5;
        A = newA;
        B = newB;
        C = newC;
    }
    cout << (A + B + C) << "\n";
    return 0;
}
