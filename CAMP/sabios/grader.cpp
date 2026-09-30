#include <bits/stdc++.h>
#include "sabios.h"












const int COMI_n = 100;

void COMI_error(std::string COMI_mensaje) {
    std::cerr << "ERROR: " << COMI_mensaje << "\n";
    exit(0);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    long long seed;
    if (!(std::cin >> n))
        COMI_error("no se pudo leer n");
    if (n != COMI_n)
        COMI_error("n debe ser 100");
    if (!(std::cin >> seed)) seed = 0;

    std::mt19937 rng((unsigned)seed);

    std::vector<int> chosen(COMI_n + 1, 0);
    int S = 0;
    bool ok = true;

    std::vector<std::pair<int,int>> pares = {{1,2}, {1,3}, {2,3}};

    for (int i = 1; i <= COMI_n; i++) {
        int p2 = (i >= 3 ? chosen[i-2] : 0);
        int p1 = (i >= 2 ? chosen[i-1] : 0);

        // Grader de prueba: pares completamente aleatorios.
        auto [a, b] = pares[rng() % 3];

        int v = elegir(i, a, b, p2, p1);

        if (v != a && v != b) {
            std::cerr << "ERROR: sabio " << i << ", respuesta " << v
                      << " no es " << a << " ni " << b << "\n";
            ok = false;
            break;
        }

        chosen[i] = v;
        S += v;
    }

    if (!ok) {
        std::cout << "Incorrecto\n";
    } else if (S == 2 * COMI_n) {
        std::cout << "Incorrecto\n";
        std::cout << "suma=" << S << " == 2n\n";
    } else {
        std::cout << "Correcto\n";
        std::cout << "suma=" << S << "\n";
    }
    return 0;
}
