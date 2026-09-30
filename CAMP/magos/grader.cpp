#include <bits/stdc++.h>
#include "magos.h"
using namespace std;

const int COMI_n_min = 1;
const int COMI_n_max = 1000;

void COMI_error(string COMI_mensaje) {
    cerr << "ERROR: " << COMI_mensaje << "\n";
    exit(0);
}

int main() {
    int COMI_n;
    cin >> COMI_n;
    if (COMI_n < COMI_n_min || COMI_n > COMI_n_max)
        COMI_error("n fuera de rango");

    vector<int> COMI_h(COMI_n + 1);
    for (int COMI_j = 1; COMI_j <= COMI_n; ++COMI_j) {
        cin >> COMI_h[COMI_j];
        if (COMI_h[COMI_j] < 0 || COMI_h[COMI_j] > 2)
            COMI_error("sombrero fuera de {0,1,2}");
    }

    vector<int> COMI_a(COMI_n + 1, -1);
    for (int COMI_i = 1; COMI_i <= COMI_n; ++COMI_i) {
        vector<int> COMI_visto;
        for (int COMI_j = 1; COMI_j <= COMI_i - 1; ++COMI_j)
            COMI_visto.push_back(COMI_a[COMI_j]);
        for (int COMI_j = COMI_i + 1; COMI_j <= COMI_n; ++COMI_j)
            COMI_visto.push_back(COMI_h[COMI_j]);

        int COMI_ans = adivinar_sombrero(COMI_n, COMI_i, COMI_visto);
        if (COMI_ans < 0 || COMI_ans > 2)
            COMI_error("respuesta fuera de {0,1,2}");
        COMI_a[COMI_i] = COMI_ans;
    }

    int COMI_aciertos = 0;
    for (int COMI_j = 1; COMI_j <= COMI_n; ++COMI_j)
        if (COMI_a[COMI_j] == COMI_h[COMI_j])
            ++COMI_aciertos;

    if (COMI_aciertos >= COMI_n - 1) {
        cout << "Correcto\n";
        cout << "n=" << COMI_n << ", aciertos=" << COMI_aciertos
             << " (se requieren >= " << (COMI_n - 1) << ")\n";
    } else {
        cout << "Incorrecto\n";
        cout << "n=" << COMI_n << ", aciertos=" << COMI_aciertos
             << " (se requieren >= " << (COMI_n - 1) << ")\n";
    }
}
