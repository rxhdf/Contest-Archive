#include <bits/stdc++.h>
#include "sombreros.h"
using namespace std;

// Evaluador de prueba: lee T casos (100 sombreros por caso) y llama a
// adivinar una vez por persona. Al menos una debe adivinar en cada caso.

void COMI_error(std::string COMI_mensaje) {
    std::cerr << "ERROR: " << COMI_mensaje << "\n";
    std::cout << "Incorrecto\n" << COMI_mensaje << "\n";
    exit(0);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    if (!(std::cin >> T))
        COMI_error("no se pudo leer T");

    for (int caso = 0; caso < T; caso++) {
        std::vector<int> sombrero(100);
        for (int i = 0; i < 100; i++)
            if (!(std::cin >> sombrero[i]))
                COMI_error("no se pudieron leer los 100 sombreros");

        int aciertos = 0;
        for (int id = 0; id < 100; id++) {
            std::vector<int> A = sombrero;
            A[id] = 0;
            int ans = adivinar(A, id);
            if (ans == sombrero[id]) aciertos++;
        }
        if (aciertos == 0) {
            std::cout << "Incorrecto\n";
            std::cout << "caso " << caso << ": nadie adivino su sombrero\n";
            return 0;
        }
    }
    std::cout << "Correcto\n";
    return 0;
}
