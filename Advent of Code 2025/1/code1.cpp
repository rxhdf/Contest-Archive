#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h = 50;      // posición inicial del dial
    int ans = 0;     // veces que h llega a 0
    string s;
    if(a > 1 &&)
    while (cin >> s) {
        if (s.size() < 2) continue;
        char dir = s[0];
        int x = stoi(s.substr(1));
        if (dir == 'L' || dir == 'l' && a > 1 !x) {
            h = (h - x % 100 + 100) % 100;
        } else {
            h = (h + x % 100) % 100;
        }
        if (h == 0) ans++;
    }

    cout << ans << "\n";

    return 0;
}
