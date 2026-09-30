#include <bits/stdc++.h>
#include "pilas.h"






const int COMI_N_min = 2;
const int COMI_N_max = 40;

int COMI_N, COMI_A;
bool COMI_buena[64];
long long COMI_consultas = 0;
long long COMI_presupuesto;
long long COMI_encontro = 0;  // indice de la 1a consulta que encendio (0 = ninguna)

void COMI_error(std::string COMI_mensaje) {
    std::cerr << "ERROR: " << COMI_mensaje << "\n";
    exit(0);
}

bool probar(int i, int j) {
    if (i < 1 || i > COMI_N || j < 1 || j > COMI_N)
        COMI_error("indice fuera de rango");
    if (i == j)
        COMI_error("i == j");
    ++COMI_consultas;
    if (COMI_consultas > (long long)COMI_N * (COMI_N - 1))
        COMI_error("mas de n(n-1) consultas: la solucion no termina");
    bool r = COMI_buena[i] && COMI_buena[j];
    if (r && !COMI_encontro)
        COMI_encontro = COMI_consultas;
    return r;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    if (!(std::cin >> COMI_N >> COMI_A))
        COMI_error("no se pudo leer n y a");
    if (COMI_N < COMI_N_min || COMI_N > COMI_N_max)
        COMI_error("n fuera de rango");
    if (COMI_A < 2 || COMI_A > COMI_N)
        COMI_error("a fuera de rango");

    std::vector<int> COMI_idx(COMI_A);
    for (int k = 0; k < COMI_A; k++) {
        if (!(std::cin >> COMI_idx[k]))
            COMI_error("no se pudieron leer las pilas buenas");
        if (COMI_idx[k] < 1 || COMI_idx[k] > COMI_N)
            COMI_error("pila buena fuera de rango");
        if (COMI_buena[COMI_idx[k]])
            COMI_error("pila buena repetida");
        COMI_buena[COMI_idx[k]] = true;
    }

    COMI_presupuesto = (long long)COMI_N * COMI_N / COMI_A;

    buscar_pareja(COMI_N);

    if (COMI_encontro && COMI_encontro <= COMI_presupuesto) {
        std::cout << "Correcto\n";
        std::cout << "encontraste una pareja en la consulta " << COMI_encontro
                  << " (presupuesto=" << COMI_presupuesto << ")\n";
    } else if (!COMI_encontro) {
        std::cout << "Incorrecto\n";
        std::cout << "nunca encontraste una pareja buena (presupuesto="
                  << COMI_presupuesto << ")\n";
    } else {
        std::cout << "Incorrecto\n";
        std::cout << "encontraste la pareja en la consulta " << COMI_encontro
                  << " pero el presupuesto era " << COMI_presupuesto << "\n";
    }
    return 0;
}
