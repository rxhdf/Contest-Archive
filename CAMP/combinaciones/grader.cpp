#include <bits/stdc++.h>
#include "combinaciones.h"
using namespace std;


struct COMI_Caso {
    int n, k;
    vector<int> a;
};

void COMI_error(string COMI_mensaje) {
    cerr << "ERROR: " << COMI_mensaje << "\n";
    exit(0);
}

vector<COMI_Caso> COMI_leer() {
    int T;
    if (!(cin >> T))
        COMI_error("no se pudo leer T");
    if (T < 1 || T > 1000)
        COMI_error("T fuera de rango");

    vector<COMI_Caso> casos(T);
    for (int i = 0; i < T; i++) {
        int n, k;
        cin >> n >> k;
        string COMI_rest;
        getline(cin, COMI_rest);
        string COMI_line;
        getline(cin, COMI_line);

        vector<int> a;
        stringstream ss(COMI_line);
        int x;
        while (ss >> x) a.push_back(x);

        if (n < 1 || n > 50)
            COMI_error("n fuera de [1, 50]");
        if (k < 0 || k > n)
            COMI_error("k fuera de [0, n]");
        if ((int)a.size() != k)
            COMI_error("cantidad de elementos no coincide con k");

        int prev = 0;
        for (int j = 0; j < k; j++) {
            if (a[j] < 1 || a[j] > n)
                COMI_error("elemento fuera de [1, n]");
            if (j > 0 && a[j] <= a[j - 1])
                COMI_error("elementos no son estrictamente crecientes");
            if (a[j] <= prev)
                COMI_error("elementos no estan ordenados");
            prev = a[j];
        }
        casos[i] = {n, k, a};
    }
    return casos;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<COMI_Caso> orig = COMI_leer();
    int T = (int)orig.size();

    vector<COMI_Caso> primero(T);
    for (int i = 0; i < T; i++) {
        auto [n2, k2, b] = combinar(orig[i].n, orig[i].k, orig[i].a);

        if (n2 != orig[i].n)
            COMI_error("la n cambio");
        if (k2 < 0 || k2 > n2)
            COMI_error("k' fuera de rango");
        if ((k2 % 2) == (orig[i].k % 2))
            COMI_error("la paridad no cambio");
        if ((int)b.size() != k2)
            COMI_error("la cantidad de elementos devueltos no coincide con k'");

        for (int j = 0; j < k2; j++) {
            if (b[j] < 1 || b[j] > n2)
                COMI_error("elemento devuelto fuera de [1, n]");
            if (j > 0 && b[j] <= b[j - 1])
                COMI_error("elementos devueltos no estan ordenados");
        }

        primero[i] = {n2, k2, b};
    }

    for (int i = 0; i < T; i++) {
        auto [n3, k3, c] = combinar(primero[i].n, primero[i].k, primero[i].a);

        if (n3 != orig[i].n || k3 != orig[i].k || c != orig[i].a)
            COMI_error("la funcion no es su propia inversa");
    }

    cout << "Correcto\n";
    return 0;
}
