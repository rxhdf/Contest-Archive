#include <bits/stdc++.h>
#include "cluedo.h"







const int COMI_M_min = 1, COMI_M_max = 6;
const int COMI_L_min = 1, COMI_L_max = 10;
const int COMI_W_min = 1, COMI_W_max = 6;
const int COMI_max_teoria = 20;

int COMI_M, COMI_L, COMI_W;
int COMI_teoria = 0;

void COMI_error(std::string COMI_mensaje) {
    std::cerr << "ERROR: " << COMI_mensaje << "\n";
    exit(0);
}

int teoria(int m, int l, int w) {
    ++COMI_teoria;
    if (COMI_teoria > COMI_max_teoria)
        COMI_error("mas de 20 teorias");
    if (m < COMI_M_min || m > COMI_M_max ||
        l < COMI_L_min || l > COMI_L_max ||
        w < COMI_W_min || w > COMI_W_max)
        COMI_error("tripleta fuera de rango");
    if (m == COMI_M && l == COMI_L && w == COMI_W) return 0;
    if (m != COMI_M) return 1;
    if (l != COMI_L) return 2;
    return 3;  // w != COMI_W
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    if (!(std::cin >> COMI_M >> COMI_L >> COMI_W))
        COMI_error("no se pudo leer la tripleta");
    if (COMI_M < COMI_M_min || COMI_M > COMI_M_max ||
        COMI_L < COMI_L_min || COMI_L > COMI_L_max ||
        COMI_W < COMI_W_min || COMI_W > COMI_W_max)
        COMI_error("tripleta secreta fuera de rango");

    auto [COMI_a, COMI_b, COMI_c] = resolver();

    if (COMI_a != COMI_M || COMI_b != COMI_L || COMI_c != COMI_W) {
        std::cout << "Incorrecto\n";
        std::cout << "secreto=(" << COMI_M << "," << COMI_L << "," << COMI_W << ")"
                  << ", devolviste (" << COMI_a << "," << COMI_b << "," << COMI_c << ")\n";
    } else {
        std::cout << "Correcto\n";
        std::cout << "secreto=(" << COMI_M << "," << COMI_L << "," << COMI_W << ")"
                  << ", teorias=" << COMI_teoria << "\n";
    }
    return 0;
}
