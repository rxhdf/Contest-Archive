#include "memorama.h"
#include <bits/stdc++.h>

using namespace std;

void Resolver(int t, int n) {
    vector<int> res(2 * n, -1);
    for(int i = 0; i < 2 * n; ++i){
        if(res[i] == -1){
            map<int, int> freq;
            map<int, vector<int>> querys;
            bool ok = false;
            int vali = -1;
            for(int j = 0; j < 2 * n; ++j){
                if(i == j || res[j] != -1)continue;

                int q = Voltea(i, j);
                querys[q].push_back(j);
                freq[q]++;

                if(freq[q] == 3){
                    ok = true;
                    vali = q;
                    break;
                }
            }
            if(ok){
                for(auto e: querys){
                    //respuesta, posiciones
                    if(e.first != vali){
                        for(int h = 0; h < e.second.size(); ++h){
                            res[e.second[h]] = e.first;
                        }
                    }
                }
            }else{
                //i tiene prioridad maxima
                for(auto e: querys){
                    for(int h = 0; h < e.second.size(); ++h){
                        res[e.second[h]] = e.first;
                    }
                }

                vector<int> aux(n, 0);
                for(int h = 0; h < 2 * n; ++h){
                    if(res[h] != -1){
                        aux[res[h]]++;
                    }
                }
                
                for(int h = 0; h < n; ++h){
                    if(aux[h] == 1){
                        res[i] = h;
                        break;
                    }
                }
                break;
            }
        }
    }
    vector<vector<int>> parejas(n);

    for(int i = 0; i < 2 * n; ++i){
        if(res[i] != -1){
            parejas[res[i]].push_back(i);
        }
    }
    for(int i = 0; i < n; ++i){
        if(parejas[i].size() > 1){
            Respuesta(parejas[i][0], parejas[i][1], i);
        }
    }
}
