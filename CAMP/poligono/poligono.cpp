#include "poligono.h"
#include <bits/stdc++.h>
using namespace std;


int distancia(int u, int v, int n){
    if(v >= u){
        return v - u;
    }else{
        return (n - u) + v;
    }
}

int asistente(int n, vector<int> a) {
    vector<int> fichas;
    for(int i = 0; i < a.size(); ++i){
        if(a[i] == 1){
            fichas.push_back(i);
        }
    }
    int mejor = -1, x = -1, y = -1;
    for(int i = 0; i < fichas.size(); ++i){
        int u = fichas[i], v = fichas[(i + 1) % fichas.size()];
        int distance = distancia(u, v, n);

        if(distance > mejor){
            mejor = distance;
            x = u, y = v;
        }
    }
    if(mejor <= n / 2){
        return y;
    }else{
        return x;
    }
}

int mago(int n, vector<int> b) {
    vector<int> fichas;
    for(int i = 0; i < b.size(); ++i){
        if(b[i] == 1){
            fichas.push_back(i);
        }
    }
    int mejor = -1, p = -1;
    for(int i = 0; i < fichas.size(); ++i){
        int u = fichas[i], v = fichas[(i + 1) % fichas.size()];
        int distance = distancia(u, v, n);

        if(distance > mejor){
            mejor = distance;
            p = u;
        }
    }
    return p % n + 1;
}