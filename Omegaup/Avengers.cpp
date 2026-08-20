// Source: https://usaco.guide/general/io
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if (!(cin >> N)) return 0;
    vector<int> A(N), B(N);
    for (int &x : A) cin >> x;
    for (int &x : B) cin >> x;
    sort(A.begin(), A.end());                  
    sort(B.begin(), B.end());
    long long PA = 0, PT = 0;                   
    for (int a : A) {
        auto it_low = lower_bound(B.begin(), B.end(), a);
        PA += it_low - B.begin();
        auto it_up  = upper_bound(B.begin(), B.end(), a);
        PT += B.end() - it_up;
    }
    if (PA > PT) {
        cout << "Avengers\n" << (PA - PT) << '\n';
    } else {
        cout << "Thanos\n" << (PT - PA + 1) << '\n';    
    }
    return 0;
}