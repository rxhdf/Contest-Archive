#include <bits/stdc++.h>
#include "cartas.h"
using namespace std;

const int COMI_n_min = 1;
const int COMI_n_max = 20;

void COMI_error(string COMI_mensaje) {
    cerr << "ERROR: " << COMI_mensaje << "\n";
    exit(0);
}

int main() {
    int COMI_n;
    cin >> COMI_n;
    if (COMI_n < COMI_n_min || COMI_n > COMI_n_max)
        COMI_error("n fuera de rango");

    vector<int> COMI_c(COMI_n);
    for (int COMI_i = 0; COMI_i < COMI_n; ++COMI_i) {
        cin >> COMI_c[COMI_i];
        if (COMI_c[COMI_i] < 0 || COMI_c[COMI_i] > 1)
            COMI_error("c_i no es binario");
    }

    int COMI_x = primera(COMI_n, COMI_c);
    if (COMI_x < 0 || COMI_x > COMI_n)
        COMI_error("x devuelto por primera() fuera de [0, n]");

    vector<vector<int>> COMI_r = segunda(COMI_n, COMI_x);
    if ((int)COMI_r.size() != 2)
        COMI_error("segunda() debe devolver un vector con dos filas");
    if ((int)COMI_r[0].size() != COMI_n || (int)COMI_r[1].size() != COMI_n)
        COMI_error("cada fila de segunda() debe tener longitud n");

    for (int COMI_i = 0; COMI_i < COMI_n; ++COMI_i) {
        if (COMI_r[0][COMI_i] < 0 || COMI_r[0][COMI_i] > 1)
            COMI_error("t[i] no es binario");
        if (COMI_r[1][COMI_i] < 0 || COMI_r[1][COMI_i] > 1)
            COMI_error("p[i] no es binario");
    }

    int COMI_up1 = 0, COMI_up2 = 0;
    for (int COMI_i = 0; COMI_i < COMI_n; ++COMI_i) {
        int COMI_estado = COMI_c[COMI_i] ^ COMI_r[0][COMI_i];
        if (COMI_r[1][COMI_i] == 1)
            COMI_up1 += COMI_estado;
        else
            COMI_up2 += COMI_estado;
    }

    if (COMI_up1 == COMI_up2) {
        cout << "Correcto\n";
        cout << "n=" << COMI_n << ", x=" << COMI_x
             << ", monton1=" << COMI_up1 << " up, monton2=" << COMI_up2 << " up\n";
    } else {
        cout << "Incorrecto\n";
        cout << "monton1=" << COMI_up1 << " boca arriba vs monton2="
             << COMI_up2 << " (x=" << COMI_x << ")\n";
    }
}
