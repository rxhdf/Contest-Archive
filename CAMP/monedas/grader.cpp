#include <bits/stdc++.h>
#include "monedas.h"

using namespace std;

const int COMI_n = 64;

void COMI_error(string mensaje) {
    cerr << "ERROR: " << mensaje << "\n";
    exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    if (!(cin >> K)) COMI_error("no se pudo leer K");
    if (K < 1 || K > 64) COMI_error("K fuera de [1, 64]");

    int c;
    if (!(cin >> c)) COMI_error("no se pudo leer c");
    if (c < 0 || c > 63) COMI_error("c fuera de [0, 63]");

    string fila;
    vector<int> b(COMI_n);
    for (int f = 0; f < 8; f++) {
        if (!(cin >> fila)) COMI_error("no se pudo leer fila");
        if ((int)fila.size() != 8) COMI_error("fila no tiene 8 caracteres");
        for (int col = 0; col < 8; col++) {
            if (fila[col] == '0') b[f * 8 + col] = 0;
            else if (fila[col] == '1') b[f * 8 + col] = 1;
            else COMI_error("caracter invalido en el tablero");
        }
    }

    vector<int> flips = arnavaz(b, c);

    if ((int)flips.size() < 1 || (int)flips.size() > K)
        COMI_error("Arnavaz voltea un numero de monedas fuera de [1, K]");

    for (int x : flips) {
        if (x < 0 || x > 63) COMI_error("casilla a voltear fuera de [0, 63]");
        b[x] ^= 1;
    }

    int ans = shahrnaz(b);

    if (ans != c) {
        cout << "Incorrecto\n";
        cout << "c=" << c << ", adivinaste " << ans << "\n";
    } else {
        cout << "Correcto\n";
    }

    return 0;
}
