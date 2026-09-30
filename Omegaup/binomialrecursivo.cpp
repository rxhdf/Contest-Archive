#include <bits/stdc++.h>
using namespace std;


int calls = 0;

int binomial(int n, int k){
    calls++;
    if(n == k || k == 0)return 1;
    return binomial(n - 1, k) + binomial(n - 1, k - 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    cout << binomial(n, k) << " " << calls << "\n";

    return 0;
}