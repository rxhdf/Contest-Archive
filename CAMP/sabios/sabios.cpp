#include "sabios.h"
#include <bits/stdc++.h>

using namespace std;

int elegir(int i, int a, int b, int p2, int p1) {
    if(i == 100){
        if(p1 == 3 && p2 == 3){
            return max(a, b);
        }
        else if((p2 == 2 && p1 == 2) || p2 == 3 && p1 == 1){
            if(a == 1 || b == 1){
                return 1;
            }else{
                return 3;
            }
        }
    }else{
       if(i == 1){
        if(a == 3 || b == 3){
            return 3;
        }else{
            return 2;
        }
       }
       else if(i == 2){
        if(p1 == 3){
            if(a == 3 || b == 3){
                return 3;
            }else{
                return 1;
            }
        }else{
            if(a == 2 || b == 2){
                return 2;
            }else{
                return 3;
            }
        }
       }else{
            // poner 3
            if(p1 == 3 && p2 == 3){
                if(a == 3 || b == 3){
                    return 3;
                }else{
                    return 2;
                }
            }
            else if(p1 == 3 && p2 != 3){
                if(a == 1 || b == 1){
                    return 1;
                }else{
                    return 3;
                }
            }
            else if(p1 == 1 && p2 == 3){
                if(a == 3 || b == 3){
                    return 3;
                }else{
                    return 2;
                }
            }
            else if(p1 == 2 && p2 == 2){
                if(a == 3 || b == 3){
                    return 3;
                }else{
                    return 2;
                }
            }
       } 
    }
}
