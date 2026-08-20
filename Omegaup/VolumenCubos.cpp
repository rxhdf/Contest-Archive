#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4;

    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    cin >> x3 >> y3 >> z3 >> x4 >> y4 >> z4;

    int X1 = min(x1, x2), X2 = max(x1, x2);
    int Y1 = min(y1, y2), Y2 = max(y1, y2);
    int Z1 = min(z1, z2), Z2 = max(z1, z2);

    int X3 = min(x3, x4), X4 = max(x3, x4);
    int Y3 = min(y3, y4), Y4 = max(y3, y4);
    int Z3 = min(z3, z4), Z4 = max(z3, z4);

    long long V1 = 1LL * (X2 - X1) * (Y2 - Y1) * (Z2 - Z1);
    long long V2 = 1LL * (X4 - X3) * (Y4 - Y3) * (Z4 - Z3);

    int Xi1 = max(X1, X3), Xi2 = min(X2, X4);
    int Yi1 = max(Y1, Y3), Yi2 = min(Y2, Y4);
    int Zi1 = max(Z1, Z3), Zi2 = min(Z2, Z4);

    long long Vi = 0;
    if (Xi1 < Xi2 && Yi1 < Yi2 && Zi1 < Zi2) {
        Vi = 1LL * (Xi2 - Xi1) * (Yi2 - Yi1) * (Zi2 - Zi1);
    }

    cout << V1 + V2 - Vi << "\n";

    return 0;
}
