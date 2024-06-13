#include <bits/stdc++.h>
#define ll unsigned long long int
using namespace std;
ll N, N1;
char A, A1;   
string S, S1;

void descifra1(){
    cin >> A >> N >> S;
    ll X = S.length() / N; 
    ll ans = 1; 
    for (ll i = 0; i < N; ++i) {
        ll ac = 0;
        for (ll j = 0; j < X; ++j) {
            ll index = i + j * N;
            ac += toupper(S[index]) - 'A' + 1;
        }
        ans = (ans * ((ac % 10) + 1)) % 10;
    }
    ll P = (ans + 1) % 10;
    cout << P << "";
}
void descifra2(){
    cin >> A1 >> N1 >> S1;
    ll X = S.length() / N; 
    ll ans = 1; 
    for (ll i = 0; i < N; ++i) {
        ll ac = 0;
        for (ll j = 0; j < X; ++j) {
            ll index = i + j * N;
            ac += toupper(S1[index]) - 'A' + 1;
        }
        ans = (ans * ((ac % 10) + 1)) % 10;
    }
    ll P1 = (ans + 1) % 10;
    cout << (char)(P1 + 'A' - 1) << "\n";
}

int main() {
    descifra1();
    descifra2();
    return 0;
}
