#include <bits/stdc++.h>
#include "dota.h"

const int COMI_carta_min = 1;
const int COMI_carta_max = 52;

void COMI_error(std::string COMI_mensaje) {
    std::cerr << "ERROR: " << COMI_mensaje << "\n";
    exit(0);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> mano(5);
    std::vector<bool> visto(53, false);
    for (int i = 0; i < 5; i++) {
        if (!(std::cin >> mano[i]))
            COMI_error("no se pudo leer carta");
        if (mano[i] < COMI_carta_min || mano[i] > COMI_carta_max)
            COMI_error("carta fuera de rango");
        if (visto[mano[i]])
            COMI_error("carta repetida");
        visto[mano[i]] = true;
    }

    std::vector<int> mostradas = asistente(mano);

    if ((int)mostradas.size() != 4)
        COMI_error("asistente no devolvio exactamente 4 cartas");

    for (int x : mostradas) {
        if (x < COMI_carta_min || x > COMI_carta_max)
            COMI_error("carta mostrada fuera de rango");
        if (!visto[x])
            COMI_error("carta mostrada no esta en la mano");
        visto[x] = false;
    }

    int escondida = -1, cuenta = 0;
    for (int i = 1; i <= COMI_carta_max; i++)
        if (visto[i]) { escondida = i; cuenta++; }

    if (cuenta != 1)
        COMI_error("las 4 cartas mostradas no dejan exactamente una carta escondida");

    int adivinada = mago(mostradas);

    if (adivinada != escondida) {
        std::cout << "Incorrecto\n";
        std::cout << "escondida=" << escondida << ", devolviste " << adivinada << "\n";
    } else {
        std::cout << "Correcto\n";
    }
    return 0;
}
