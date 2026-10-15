#include "combo.h"
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;


string adivinar_combo(int n) {
    string ans = "";
    vector<char> disponible = {'A', 'B', 'X', 'Y'};
    //AB - XY
    if(presionar("AB")){
        if(presionar("A")){
            ans += "A";
        }else{
            ans += "B";
        }
    }else{
        if(presionar("X")){
            ans += "X";
        }else{
            ans += "Y";
        }
    }

    disponible.erase(find(disponible.begin(), disponible.end(), ans[0]));

    char separador = ans[0];

    //caracteres desde 1 a n - 1
    //prefijo + A, separador, Prefijo + BA, separador, Prefijo + BB, separador, Prefijo + BC
    // 1 + size -> A
    // 2 + size --> B
    // 0 + size --> C

    char A = disponible[0], B = disponible[1], C = disponible[2];

    for(int i = 1; i < n; ++i){
        string t;
        if(i == n - 1){
            t += ans;
            t += A;
            t += ans;
            t += B;
            //cerr << t << " " << t.size() << endl;

            if(presionar(t) > ans.size()){
                t = ans;
                t += A;
                //cerr << "holan " << t.size() << endl;
            if(presionar(t) > ans.size()){
                    return t;
                }
                ans += B;
            }else{
                ans += C;
            }
            break;
        }
        t = ans;
        t += A;
        for(auto c: disponible){
            t += ans;
            t += B;
            t += c;
        }
        int q = presionar(t);
        if(q == ans.size() + 1){
            ans += A;
        }
        else if(q == ans.size()){
            ans += C;
        }else{
            ans += B;
        }   
    }

    cerr << ans << endl;
    return ans;
}
