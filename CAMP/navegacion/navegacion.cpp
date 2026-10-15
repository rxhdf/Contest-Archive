#include "navegacion.h"
#include <bits/stdc++.h>

using namespace std;

// Estrategia de Anna: Colorea el tablero usando solo 0 y 1 en base a los cuadrantes respecto a T
#include "navegacion.h"
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> anna(int R, int C, int tr, int tc) {
    vector<vector<int>> mat(R, vector<int>(C));

    // Codificación vertical.
    vector<int> a(R);

    if (tr == R - 1) {
        // Si T está en la última fila, dejamos toda la columna
        // verticalmente constante. La frontera inferior distingue a T.
        for (int i = 0; i < R; ++i)
            a[i] = 0;
    } else {
        // Arriba de T: 0,0,0,0,...
        // T: 0
        // Debajo: 1,0,1,0,1,0,...
        for (int i = 0; i < R; ++i) {
            if (i <= tr)
                a[i] = 0;
            else
                a[i] = (i - tr) & 1;
        }
    }

    // Codificación horizontal.
    vector<int> b(C);

    if (tc == C - 1) {
        // Caso simétrico: T está en la última columna.
        for (int j = 0; j < C; ++j)
            b[j] = 0;
    } else {
        // Izquierda de T: 0,0,0,0,...
        // T: 0
        // Derecha: 1,0,1,0,1,0,...
        for (int j = 0; j < C; ++j) {
            if (j <= tc)
                b[j] = 0;
            else
                b[j] = (j - tc) & 1;
        }
    }

    // Combinamos ambas codificaciones.
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            mat[i][j] = a[i] ^ b[j];
            cerr << mat[i][j];
        }
        cerr << endl;
    }

    return mat;
}

// Estrategia de Bruno: Toma decisiones locales garantizando que siempre se acorte la distancia a T
char bruno(int yo, int N, int S, int O, int E) {

    /*
        Primero determinamos la posición vertical relativa a T.

        Estados posibles:

        - ARRIBA:      hay que ir hacia S
        - ABAJO:       hay que ir hacia N
        - MISMA FILA:  pasamos a analizar horizontalmente

        La comparación de colores funciona aunque el color haya
        sido complementado por el componente horizontal, porque
        solamente usamos igualdad/desigualdad.
    */

    // Caso de estar en la última fila.
    if (S == -1) {
        if (N == -1 || N == yo) {
            // Estamos en la fila objetivo.
        } else {
            // Estamos debajo de T.
            return 'N';
        }
    } else {
        // Si N es distinto, estamos debajo de T.
        if (N != -1 && N != yo) {
            return 'N';
        }

        // Si S es distinto y N no lo es, estamos en la fila de T.
        if (S != yo) {
            // misma fila
        } else {
            // Estamos arriba de T.
            return 'S';
        }
    }

    /*
        Estamos en la fila objetivo.
        Ahora analizamos la posición horizontal.
    */

    // Caso de estar en la última columna.
    if (E == -1) {
        if (O == -1 || O == yo) {
            // Estamos en T.
            return 'H';
        } else {
            // Estamos a la derecha de T.
            return 'O';
        }
    }

    // A la derecha de T.
    if (O != -1 && O != yo) {
        return 'O';
    }

    // Misma columna que T.
    if (E != yo) {
        return 'H';
    }

    // A la izquierda de T.
    return 'E';
}