#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, P;
    cin >> N >> P;
    P %= 3;
    int up = (N + P) % 3, down = abs(N - P + 3) % 3;
    if(up == 0)up = 3;
    if(down == 0)down = 3;
    cout << down << " " << up << "\n";
    return 0;
}