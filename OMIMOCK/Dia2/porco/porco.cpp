#include "porco.h"
#include <bits/stdc++.h>
#include <utility>
using namespace std;

int mapeado[52][52];

vector<vector<int>> inicializar(int n, int s) {
    memset(mapeado, 0, sizeof(mapeado));
    //subtarea1
    //probar llegar a la permutacion Q haciendo intercambios entre indinces i, j
    vector<vector<int>> patrones;
    vector<int> p;
    for(int i = 1; i <= n; ++i){
        p.push_back(i);
    }
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            if(i == j)continue;
            mapeado[i][j] = mapeado[j][i] = ++cnt;
            swap(p[i], p[j]);
            for(int h = 0; h < n; ++h){
                //cerr << p[h] << " ";
            }
            //cerr << "\n";
            patrones.push_back(p);
            swap(p[i], p[j]);    
        }
    }
    return patrones;
}

vector<int> resolver(vector<int> P) {
    vector<int> secuencia;
    int n = P.size();
    vector<int> R;
    for(int i = 1; i <= n; ++i){
        R.push_back(i);
    }
    for(int i = 0; i < n; ++i){
        if(R[i] != P[i]){
            for(int j = 0; j < n; ++j){
                if(R[j] == P[i]){
                    //debo intercambiar (i, j);
                    int id = mapeado[i][j];
                    secuencia.push_back(id);
                    swap(R[i], R[j]);
                    break;
                }
            }
        }
    }
    return secuencia;
}
