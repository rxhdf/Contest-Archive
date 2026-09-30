#include <bits/stdc++.h>
#include "prisioneros.h"

const int COMI_n_min = 1;
const int COMI_n_max = 100000;

int COMI_n;
std::vector<int> COMI_mod;
std::vector<int> COMI_pos;
int COMI_consultas = 0;

void COMI_error(std::string COMI_mensaje) {
    std::cerr << "ERROR: " << COMI_mensaje << "\n";
    exit(0);
}

int abrir_cajon(int i) {
    ++COMI_consultas;
    if (COMI_consultas > COMI_n)
        COMI_error("mas de n cajones abiertos");
    if (i < 1 || i > 2 * COMI_n)
        COMI_error("indice de cajon fuera de rango");
    return COMI_mod[i];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    if (!(std::cin >> COMI_n))
        COMI_error("no se pudo leer n");
    if (COMI_n < COMI_n_min || COMI_n > COMI_n_max)
        COMI_error("n fuera de rango");

    std::vector<int> COMI_per(2 * COMI_n + 1);
    for (int i = 1; i <= 2 * COMI_n; ++i) {
        if (!(std::cin >> COMI_per[i]))
            COMI_error("no se pudo leer permutacion");
        if (COMI_per[i] < 1 || COMI_per[i] > 2 * COMI_n)
            COMI_error("valor de permutacion fuera de rango");
    }

    std::pair<int,int> cambio = ayudante(COMI_n, COMI_per);
    if (cambio.first < 1 || cambio.first > 2 * COMI_n ||
        cambio.second < 1 || cambio.second > 2 * COMI_n)
        COMI_error("intercambio fuera de rango");

    COMI_mod = COMI_per;
    COMI_pos.assign(2 * COMI_n + 1, -1);
    auto [i, j] = cambio;
    if (i != j)
        std::swap(COMI_mod[i], COMI_mod[j]);
    for (int p = 1; p <= 2 * COMI_n; ++p)
        COMI_pos[COMI_mod[p]] = p;

    bool COMI_ok = true;
    int COMI_total_consultas = 0;
    for (int v = 1; v <= 2 * COMI_n; ++v) {
        COMI_consultas = 0;
        int COMI_ans = prisionero(COMI_n, v);
        COMI_total_consultas += COMI_consultas;
        if (COMI_ans != COMI_pos[v]) {
            std::cout << "Incorrecto\n";
            std::cout << "v=" << v
                      << ", devolviste " << COMI_ans
                      << ", esperado " << COMI_pos[v] << "\n";
            COMI_ok = false;
            break;
        }
    }

    if (COMI_ok) {
        std::cout << "Correcto\n";
        std::cout << "total de consultas=" << COMI_total_consultas << "\n";
    }
    return 0;
}
