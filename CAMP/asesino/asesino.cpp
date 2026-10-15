#include "asesino.h"
#include <bits/stdc++.h>

using namespace std;

int encontrar_asesino(int n) {
    if(n == 3){

    }
    else if(n % 2 == 0){
        for(int i = 1; i <= n - 1; i += 2){
            //i, i + 1;
            int pregunta1 = preguntar(i, i + 1);
            int pregunta2 = preguntar(i + 1, i);
            if(pregunta1 != pregunta2){
                //asesino en esta pareja
                if(i == n - 1){
                    if(preguntar(i, i - 1) != preguntar(i - 1, i)){
                        return i;
                    }else{
                        return i + 1;
                    }
                }
            }else{
                continue;
            }
        }
    }else{

    }
    return 1;
}
