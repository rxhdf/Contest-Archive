#include <bits/stdc++.h>
#include "poligono.h"
using namespace std;

void COMI_error(string COMI_mensaje) {
    cerr << "ERROR: " << COMI_mensaje << "\n";
    exit(0);
}

int main() {
    int COMI_n;
    cin >> COMI_n;
    if (COMI_n < 2 || COMI_n > 100 || COMI_n % 2 != 0)
        COMI_error("n fuera de rango o no par");

    vector<int> COMI_a(COMI_n + 1);
    for (int COMI_i = 1; COMI_i <= COMI_n; COMI_i++) {
        cin >> COMI_a[COMI_i];
        if (COMI_a[COMI_i] < 0 || COMI_a[COMI_i] > 1)
            COMI_error("a_i no es binario");
    }

    int COMI_ones = 0;
    for (int COMI_i = 1; COMI_i <= COMI_n; COMI_i++)
        COMI_ones += COMI_a[COMI_i];
    if (COMI_ones < 2)
        COMI_error("se requieren al menos 2 fichas");

    int COMI_q = asistente(COMI_n, COMI_a);
    if (COMI_q < 1 || COMI_q > COMI_n)
        COMI_error("q fuera de [1, n]");
    if (COMI_a[COMI_q] != 1)
        COMI_error("q no tiene ficha");

    vector<int> COMI_b = COMI_a;
    COMI_b[COMI_q] = 0;

    int COMI_i = mago(COMI_n, COMI_b);
    if (COMI_i < 1 || COMI_i > COMI_n)
        COMI_error("i fuera de [1, n]");

    int COMI_mitad = COMI_n / 2;
    int COMI_dist = (COMI_q - COMI_i + COMI_n) % COMI_n;
    if (COMI_dist >= 0 && COMI_dist < COMI_mitad) {
        cout << "Correcto\n";
        cout << "n=" << COMI_n << ", q=" << COMI_q << ", i=" << COMI_i << "\n";
    } else {
        cout << "Incorrecto\n";
        cout << "q=" << COMI_q << " no cae en la mitad que inicia en i=" << COMI_i << "\n";
    }
}
