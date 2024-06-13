#include <bits/stdc++.h>
#define MAX (int)100001

using namespace std;

int sieve[MAX];
int primes[MAX];

void fill_sieve() {
    for(int i = 2; i <= MAX; ++i)sieve[i] = i;
    sieve[0] = sieve[1] = 1;
    for( int i = 2; i * i < MAX; i++ ) {
        if(sieve[i] == i) {
            primes[i]++;
            for( int j = i*i; j < MAX; j+=i ) {
                sieve[j] = i;
            }
        }
    }
}
auto count(int X){
    int aux = 0;
    if(X <= 1)return 0;
    while(X > 1){
        X /= sieve[X];
        aux++;
    }
    return aux;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int A, B, ans = 0;
    cin >> A >> B;
    fill_sieve();
    for(int i = A; i <= B; ++i){
        if(primes[count(i)])ans++;
    }
    cout << ans << "\n";
    return 0;
}