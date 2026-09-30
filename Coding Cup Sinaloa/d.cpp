#include <bits/stdc++.h>
using namespace std;


//Definir el MOdulo
const long long MOD = 1e9 + 7;

long long mp(long long a, long long b, long long mod){
    long long res = 1;
    a %= mod;
    while (b > 0) {
        //Checar si mi numero es impar
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long N;
    int K;
    cin >> N >> K;
    long long p = mp(10, N, MOD);
    long long num = (p - 1 + MOD) % MOD;
    long long inv9 = mp(9, MOD - 2, MOD), result;

    result = (1LL * K * num) % MOD;
    result = (result * inv9) % MOD;
    cout << result << "\n";

    return 0;
}
