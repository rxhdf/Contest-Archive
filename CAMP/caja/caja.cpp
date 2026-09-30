#include "caja.h"
#include <bits/stdc++.h>

using namespace std;

pair<int, int> encontrar_caja(int h, int w) {
    for(int r = 0; r < h; ++r){
        for(int c = 0; c < w; ++c){
            if(r == 0 && c == 0)continue;
            string s = "";
            for(int i = 0; i < r; i++)s += 'v';
            for(int i = 0; i < c; i++)s += '>';

            pair<int, int> q = consultar(s);

            if(q != make_pair(r, c)){
                if(q.first < r && q.second == 0){
                    return {q.first + 1, 0};
                }else{
                    return {r, q.second + 1};
                }
            }
        }
    }
    return {0, 0};
}