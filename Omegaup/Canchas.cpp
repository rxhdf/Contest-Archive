#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int x1, x2, x3, x4, y1, y2, y3, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    int X1 = min(x1, x2), X2 = max(x1, x2);
    int Y1 = min(y1, y2), Y2 = max(y1, y2);

    int X3 = min(x3, x4), X4 = max(x3, x4);
    int Y3 = min(y3, y4), Y4 = max(y3, y4);

    long long A1 = 1LL * (X2 - X1) * (Y2 - Y1);
    long long A2 = 1LL * (X4 - X3) * (Y4 - Y3);

    int Xi1 = max(X1, X3), Xi2 = min(X2, X4);
    int Yi1 = max(Y1, Y3), Yi2 = min(Y2, Y4);

    long long Ai = 0;
    if (Xi1 < Xi2 && Yi1 < Yi2) {
        Ai = 1LL * (Xi2 - Xi1) * (Yi2 - Yi1);
    }
    cout << A1 + A2 - Ai << "\n";    
    return 0;
}