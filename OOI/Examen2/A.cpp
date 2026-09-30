#include <bits/stdc++.h>
#include <cstdint>
#define ll unsigned long long
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

ll memo[101][101][101];
ll cnt = 0;

ll f(int a, int b, int c){
    if(memo[a][b][c] != -1)return memo[a][b][c];
    cnt++;
    if(min(a, min(b, c)) <= 3){
        return memo[a][b][c] = a + (2 * b) + (3 * c);
    }
    else if(min(a, min(b, c)) > 3 && (a + b + c == 100)){
            return memo[a][b][c] = 0;
    }
    return memo[a][b][c] = f(a - 1, b - 1, c - 1) + f(a, b - 3, c - 3) + f(floor(a / 2), b, c);
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    memset(memo, -1, sizeof(memo));
    cout << f(a, b, c) << " " << cnt<< "\n";

    return 0;
}