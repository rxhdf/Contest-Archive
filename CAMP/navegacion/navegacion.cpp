#include "navegacion.h"
#include <bits/stdc++.h>
#define ARRIBA 0 
#define ABAJO 1
#define IZQUIERDA 1
#define DERECHA 0

using namespace std;

vector<vector<int>> anna(int R, int C, int tr, int tc) {
    vector<vector<int>> matriz(R, vector<int>(C, 1));
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            if((j <= tc && i < tr) || (j <= tc && i > tr)){
                matriz[i][j] = DERECHA;
            }
            else if((j >= tc && i < tr) || (j >= tc && i > tr)){
                matriz[i][j] = IZQUIERDA;
            }
        }
    }
    
    matriz[tr][tc] = 1;

    return matriz;
}

char bruno(int yo, int N, int S, int O, int E) {
    
    if(yo == DERECHA){
        if(E == IZQUIERDA){
            return 'N';
        }
    }

    return 'H';
}
