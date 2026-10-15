#include <bits/stdc++.h>
#include "asesino.h"

int COMI_N, COMI_limite, COMI_usadas, COMI_total;
std::vector<int> COMI_rol;

int COMI_tabla(int ri, int rj) {
    static const int T[3][3] = {{1, 0, 1}, {0, 1, 0}, {0, 1, 0}};
    return T[ri][rj];
}

int preguntar(int i, int j) {
    if (i < 1 || i > COMI_N || j < 1 || j > COMI_N) {
        std::cout << "Incorrecto\npreguntar(" << i << ", " << j << ") fuera de rango\n";
        exit(0);
    }
    if (i == j) {
        std::cout << "Incorrecto\npreguntar con i == j\n";
        exit(0);
    }
    COMI_total++;
    if (++COMI_usadas > COMI_limite) {
        std::cout << "Incorrecto\n";
        std::cout << "usaste " << COMI_usadas << " preguntas\n";
        exit(0);
    }
    return COMI_tabla(COMI_rol[i - 1], COMI_rol[j - 1]);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    if (!(std::cin >> t)) {
        std::cerr << "ERROR: no se pudo leer t\n";
        return 0;
    }
    for (int caso = 0; caso < t; caso++) {
        if (!(std::cin >> COMI_N)) {
            std::cerr << "ERROR: no se pudo leer n\n";
            return 0;
        }
        COMI_rol.assign(COMI_N, 0);
        int asesinos = 0;
        for (int i = 0; i < COMI_N; i++) {
            if (!(std::cin >> COMI_rol[i])) {
                std::cerr << "ERROR: no se pudieron leer los roles\n";
                return 0;
            }
            asesinos += (COMI_rol[i] == 2);
        }
        if (asesinos != 1) {
            std::cerr << "ERROR: debe haber exactamente un Asesino (rol 2)\n";
            return 0;
        }
        COMI_limite = (COMI_N == 3) ? 4 : COMI_N;
        COMI_usadas = 0;

        int acusado = encontrar_asesino(COMI_N);
        int real = -1;
        for (int i = 0; i < COMI_N; i++)
            if (COMI_rol[i] == 2) real = i + 1;

        if (acusado != real) {
            std::cout << "Incorrecto\n";
            std::cout << "caso " << caso + 1 << ": el Asesino era " << real
                      << ", acusaste a " << acusado << "\n";
            return 0;
        }
    }
    std::cout << "Correcto\n";
    std::cout << "preguntas totales=" << COMI_total << "\n";
    return 0;
}
