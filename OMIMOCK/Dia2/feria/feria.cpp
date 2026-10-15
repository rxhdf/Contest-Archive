#include "feria.h"
#include <bits/stdc++.h>
using namespace std;

vector<int> encriptar(int n, int k, vector<int> T) {
    vector<int> ans;
    if(k == 2){
        int pareja1 = (T[0] + 1) / 2;
        int pareja2 = (T[1] + 1) / 2;
        if(pareja1 != pareja2){
            int r1, r2;
            if(T[0] & 1){
                r1 = T[0] + 1;
            }else{
                r1 = T[0] - 1;
            }
            if(T[1] & 1){
                r2 = T[1] + 1;
            }else{
                r2 = T[1] - 1;
            }
            if(r1 > n) r1 = T[0] - 2;
            if(r2 > n) r2 = T[1] - 2;
            ans = {r1, r2};
        }else{
            int nxt = pareja1 + 1;
            if(nxt > (n / 2))nxt = 1;
            ans = {2 * nxt - 1, 2 * nxt};
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

vector<int> desencriptar(int n, int k, vector<int> R) {
    int r1 = R[0], r2 = R[1];
    vector<int> ans;
    if(k == 2){
        int p1 = (r1 + 1) / 2;
        int p2 = (r2 + 1) / 2;
        if(p1 != p2){
            int t1, t2;
            if(r1 & 1){
                t1 = r1 + 1;
            }else{
                t1 = r1 - 1;
            }
            if(r2 & 1){
                t2 = r2 + 1;
            }else{
                t2 = r2 - 1;
            }
            ans = {t1, t2};
        }else{
            int prev = p1 - 1;
            if(prev < 1)prev = n / 2;
            ans = {2 * prev - 1, 2 * prev};
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
