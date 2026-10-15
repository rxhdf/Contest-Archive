#include <bits/stdc++.h>
#include "feria.h"
using namespace std;

static void COMI_error(const char* COMI_msg) {
    printf("Incorrecto: %s\n", COMI_msg);
    exit(0);
}

int main() {
    int COMI_n, COMI_k;
    if (scanf("%d %d", &COMI_n, &COMI_k) != 2) {
        COMI_error("la entrada no contiene n y k");
    }

    vector<int> COMI_T(COMI_k);
    for (int COMI_j = 0; COMI_j < COMI_k; COMI_j++) {
        if (scanf("%d", &COMI_T[COMI_j]) != 1) {
            COMI_error("la entrada no contiene todos los elementos de T");
        }
    }

    // Sofia cifra el mensaje.
    vector<int> COMI_R = encriptar(COMI_n, COMI_k, COMI_T);
    if ((int)COMI_R.size() != COMI_k) {
        COMI_error("encriptar no retorno exactamente k elementos");
    }
    for (int COMI_j = 0; COMI_j < COMI_k; COMI_j++) {
        if (COMI_R[COMI_j] < 1 || COMI_R[COMI_j] > COMI_n) {
            COMI_error("encriptar retorno un elemento fuera de rango [1, n]");
        }
        if (COMI_j > 0 && COMI_R[COMI_j] <= COMI_R[COMI_j - 1]) {
            COMI_error("encriptar no retorno elementos distintos en orden creciente");
        }
        if (binary_search(COMI_T.begin(), COMI_T.end(), COMI_R[COMI_j])) {
            COMI_error("encriptar retorno un elemento que comparte con T");
        }
    }

    // Alejandra descifra.
    vector<int> COMI_dec = desencriptar(COMI_n, COMI_k, COMI_R);
    if (COMI_dec != COMI_T) {
        COMI_error("desencriptar no recupero el mensaje original");
    }

    printf("Correcto: el mensaje se cifro y descifro correctamente\n");
    return 0;
}
