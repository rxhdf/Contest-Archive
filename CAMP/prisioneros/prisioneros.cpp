#include "prisioneros.h"
#include <bits/stdc++.h>
using namespace std;

pair<int,int> ayudante(int n, vector<int> P) {
    vector<vector<int>> cycles(2 * n + 1);
    vector<bool> visited(2 * n + 1, false);
    for(int i = 1; i <= 2 * n; ++i){
        if(P[i] != i && !visited[i]){
            int position = 0;
            visited[i] = true;
            cycles[i].push_back(i);
            for(position = P[i]; position != i; position = P[position]){
                cycles[i].push_back(position);
                visited[position] = true;
            }
            visited[position] = true;
        }
    }
    int i = 1, j = 1;
    for(auto cycle: cycles){
        if(cycle.size() > n){
            i = cycle[0];
            j = cycle[n];
        }
    }
    return {i, j};
}

int prisionero(int n, int v) {
    int cajon_actual = v;
    while(true){
        int contenido = abrir_cajon(cajon_actual);
        if(contenido == v){
            return cajon_actual;
        }
        cajon_actual = contenido;
    }
    return cajon_actual;
}
