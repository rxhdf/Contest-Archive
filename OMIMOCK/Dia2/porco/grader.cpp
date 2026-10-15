#include <bits/stdc++.h>
#include "porco.h"
using namespace std;

static void COMI_error(const char* msg) {
    printf("Incorrecto: %s\n", msg);
    exit(0);
}

static int COMI_maxactivaciones(int n, int s) {
    if (s == 2 || s == 3) return 2 * n;
    return 2 * n * n;
}

int main() {
    int COMI_n, COMI_s;
    if (scanf("%d %d", &COMI_n, &COMI_s) != 2) {
        COMI_error("la entrada no contiene n y s");
    }

    vector<int> COMI_objetivo(COMI_n);
    for (int COMI_i = 0; COMI_i < COMI_n; COMI_i++) {
        if (scanf("%d", &COMI_objetivo[COMI_i]) != 1) {
            COMI_error("la entrada no contiene el cableado objetivo");
        }
    }

    vector<vector<int>> COMI_patrones = inicializar(COMI_n, COMI_s);
    int COMI_m = (int)COMI_patrones.size();

    for (int COMI_i = 0; COMI_i < COMI_m; COMI_i++) {
        if ((int)COMI_patrones[COMI_i].size() != COMI_n) {
            COMI_error("un patron no tiene n elementos");
        }
        vector<bool> COMI_visto(COMI_n + 1, false);
        for (int COMI_j = 0; COMI_j < COMI_n; COMI_j++) {
            int COMI_x = COMI_patrones[COMI_i][COMI_j];
            if (COMI_x < 1 || COMI_x > COMI_n || COMI_visto[COMI_x]) {
                COMI_error("un patron no es una permutacion de 1..n");
            }
            COMI_visto[COMI_x] = true;
        }
    }

    vector<int> COMI_secuencia = resolver(COMI_objetivo);
    int COMI_k = (int)COMI_secuencia.size();

    if (COMI_k > COMI_maxactivaciones(COMI_n, COMI_s)) {
        COMI_error("la secuencia excede el limite de activaciones");
    }

    vector<int> COMI_R(COMI_n);
    for (int COMI_i = 0; COMI_i < COMI_n; COMI_i++) {
        COMI_R[COMI_i] = COMI_i + 1;
    }
    for (int COMI_i = 0; COMI_i < COMI_k; COMI_i++) {
        int COMI_a = COMI_secuencia[COMI_i];
        if (COMI_a < 1 || COMI_a > COMI_m) {
            COMI_error("la secuencia contiene un patron fuera de rango");
        }
        vector<int> COMI_aux(COMI_n);
        for (int COMI_j = 0; COMI_j < COMI_n; COMI_j++) {
            COMI_aux[COMI_j] = COMI_R[COMI_patrones[COMI_a - 1][COMI_j] - 1];
        }
        COMI_R = COMI_aux;
    }

    if (COMI_R != COMI_objetivo) {
        COMI_error("la configuracion obtenida es diferente al objetivo");
    }

    printf("Correcto. Patrones: %d, activaciones: %d\n", COMI_m, COMI_k);
    return 0;
}
