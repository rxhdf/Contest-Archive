#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> alturas(n);

    for(auto &e: alturas){
        cin >> e;
    }

    stack<ll> pila;
    pila.push(-1);
    alturas.push_back(-1);
    ll amax = 0;
    for(int i = 0; i <= n; ++i){
        while(pila.top() != -1 && alturas[pila.top()] >= alturas[i]){
            int tope = pila.top();
            pila.pop();

            ll ancho = i - 1 - pila.top();
            ll area = ancho * alturas[tope];

            amax = max(area, amax);

        }
        pila.push(i);
    }
    cout << amax << "\n";
}

//-1