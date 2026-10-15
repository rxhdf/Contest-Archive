#include "caja.h"
#include <bits/stdc++.h>
using namespace std;

std::pair<int,int> encontrar_caja(int h, int w) {
    if(h == 1){
        pair<int, int> query = consultar(string(w - 1, '>'));
        return {0, query.second + 1};
    }
    if(w == 1){
        pair<int, int> query = consultar(string(h - 1, 'v'));
        return {query.first + 1, 0};
    }

    string left(w - 1, '<'), right(w - 1, '>');
    string s = right + left + "v";
    for(int i = 1; i < h; ++i){
        //fila por fila y bordear la caja
        s += right + "^>v" + left + "v";
    }
    s += right;
    pair<int, int> query = consultar(s);
    if(query == make_pair(h - 1, w - 1)){
        pair<int, int> aux = consultar(right);
        //esta en la primer columna
        if(aux.second == w - 1){
            return {1, 0};
        }
        //esta en la primer fila
        return {0, aux.second + 1};
    }
    if(query.second == w - 1){
        return {query.first + 1, 0};
    }
    //nos quedamos en un loop y esta en la columna de enfrente
    return {query.first, query.second + 1};
}
