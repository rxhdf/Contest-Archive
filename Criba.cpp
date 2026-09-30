#include <bits/stdc++.h>
#include <cstdint>

using namespace std;

vector<bool> criba; // marcar multiplos
vector<int> primos; // almacenar numeros primos

void generar_criba(int n){
    for(int i = 2; i <= n; ++i){
        if(criba[i] == true)continue;
        for(int j = 2 * i; j <= n; j += i){
            criba[j] = true;
        }
    }
}

vector<int> factorizacion_prima(int n){
    vector<int> factores;
    for(int i = 2; i * i <= n; ++i){
        while(n % i == 0){
            factores.push_back(i);
            n /= i;
        }
    }
    if(n > 1){
        factores.push_back(n);
    }
    return factores;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    criba.resize(n + 1, 0);
    generar_criba(n);
    for(int i = 0; i < criba.size(); ++i){
        if(!criba[i])cout << i << ' ';
    }
    cout << "\n";
    vector<int> ans = factorizacion_prima(n);
    for(int i = 0; i < ans.size(); ++i){
        cout << ans[i] << ' ';
    }

    return 0;
}