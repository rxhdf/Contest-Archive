#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    while (getline(cin, s)) {
        for (char &c : s)if (!isdigit(c)) c = ' ';
        stringstream ss(s);
        long long x, ans = 0;
        while (ss >> x) ans += x;
        cout << ans << "\n";
    }
}
