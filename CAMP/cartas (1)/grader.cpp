#include <bits/stdc++.h>
#include "cartas.h"

void COMI_error(std::string COMI_mensaje) {
    std::cerr << "ERROR: " << COMI_mensaje << "\n";
    std::cout << "Incorrecto\n" << COMI_mensaje << "\n";
    exit(0);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K, Q;
    if (!(std::cin >> N >> K >> Q))
        COMI_error("no se pudo leer N K Q");

    for (int q = 0; q < Q; q++) {
        std::vector<int> elec(K);
        std::vector<bool> enElec(N + 1, false);
        for (int i = 0; i < K; i++) {
            if (!(std::cin >> elec[i]))
                COMI_error("no se pudo leer la eleccion");
            enElec[elec[i]] = true;
        }

        std::vector<int> mesa = asistente(N, K, elec);

        if ((int)mesa.size() != K - 1)
            COMI_error("asistente no devolvio exactamente K-1 cartas");
        int descartada = -1;
        for (int x : mesa) {
            if (x < 1 || x > N)
                COMI_error("carta de la mesa fuera de rango");
            if (!enElec[x])
                COMI_error("carta de la mesa no esta en la eleccion");
            enElec[x] = false;
        }
        for (int c : elec)
            if (enElec[c]) descartada = c;

        int adivinada = mago(N, K, mesa);

        if (adivinada != descartada) {
            std::cout << "Incorrecto\n";
            std::cout << "truco " << q << ": descartada=" << descartada
                      << ", devolviste " << adivinada << "\n";
            return 0;
        }
    }
    std::cout << "Correcto\n";
    return 0;
}
