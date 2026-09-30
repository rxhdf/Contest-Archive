#include "cartas.h"
using namespace std;

int primera(int n, vector<int> c) {
    int x = 0;
    for(auto e : c){
        if(e == 1){
            x++;
        }
    }
    return x;
}


vector<vector<int>> segunda(int n, int x) {
    vector<int> t(n, 0), p(n, 0);
    for(int i = 0; i < x; ++i){
        t[i] = 1;
        p[i] = 1;
    }

    return {t, p};
}
