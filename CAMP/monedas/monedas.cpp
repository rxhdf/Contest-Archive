#include "monedas.h"
#include <bits/stdc++.h>

using namespace std;


vector<int> arnavaz(vector<int> b, int c) {
    // Programa tu solucion aqui.
    long long s = 0;
    for(int i = 0; i < b.size(); ++i){
        if(b[i]){
            s ^= i;
        }
    }
    int v = s ^ c;
    vector<int> pos = {v};
    return pos;
}

int shahrnaz(vector<int> b) {
    // Programa tu solucion aqui.
    int aux = 0;
    for(int i = 0; i < b.size(); ++i){
        if(b[i]){
            aux ^= i;
        }
    }
    return aux;
}