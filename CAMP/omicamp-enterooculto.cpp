#include <bits/stdc++.h>                                                                                                                                                                
//#include "entero.h"
// Declaracion adelantada del evaluador. COMENTALA al enviar tu solucion.
//bool pregunta(int y);

int adivina() {
    int l = 1;
    int r = 1000000000;

    while(l < r){
        int m = l + (r - l) / 2;
        if(pregunta(m)){
            l = m + 1;
        }else{
            r = m;
        }
    }

    return l;
}