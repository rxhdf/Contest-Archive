#include "pilas.h"
#include <bits/stdc++.h>

using namespace std;

void buscar_pareja(int n) {
    for(int i = 1; i <= (n / 2); ++i){
        for(int j = 1; j <= n; ++j){
            int nxt = (j + i) % n;
            if(nxt == 0)nxt = n;
            if(j != nxt){
                if(probar(j, nxt)){
                    return;
                } 
            }
                
        }
    }
}   
