#include "cluedo.h"
#include <bits/stdc++.h>

std::tuple<int,int,int> resolver() {
    // Programa tu solucion aqui.
    std::tuple<int, int, int> ans;
    int i, j, k;
    i = j = k = 1;
    int pista = teoria(i, j, k);
    while(pista){
       if(pista == 1){
        ++i;
       }else if(pista == 2){
        ++j;
       }
       else if(pista == 3){
        ++k;
       }
       pista = teoria(i, j, k);
    }
    return ans = {i, j, k};
}
