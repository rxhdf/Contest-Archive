#include "dota.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <iterator>

using namespace std;


bool equal(vector<int> &a, vector<int> &b){
    for(int i = 0; i < a.size(); ++i){
        if(a[i] != b[i])return false;
    }
    return true;
}

vector<int> asistente(vector<int> a) {
    map<int, vector<int>> palos;
    for(int i = 0; i < a.size(); ++i){
        int palo = (a[i] - 1) / 13;
        palos[palo].push_back(a[i]);
    }
    int bg = 0, start = INT32_MAX;
    for(auto e: palos){
        if(e.second.size() >= 2){
            bg = e.second[0];
            start = e.second[1];
            break;
        }
    }   

    int visible, hidden, distance;
    int bga = (bg - 1) % 13;
    int starta = (start - 1) % 13;
    if(((bga - starta + 13) % 13) <= 6){
        visible = start;
        hidden = bg;
        distance = ((bga - starta + 13) % 13);
    }else{
        visible = bg;
        hidden = start;
        distance = ((starta - bga + 13) % 13);
    }

    vector<int> perm;
    for(int i = 0; i < a.size(); ++i){
        if(a[i] != bg && a[i] != start){
            perm.push_back(a[i]);
        } 
    }
    sort(perm.begin(), perm.end());
    int cnt = 0;
    for(int i = 1; i < distance; ++i){
        next_permutation(perm.begin(), perm.end());
    }
    
    vector<int> ans = {visible};
    for(int i = 0; i < 3; ++i){
        ans.push_back(perm[i]);
    }

    return ans;
}

int mago(vector<int> b) {
    int visible = b[0];
    vector<int> aux = {b[1], b[2], b[3]};
    vector<int> perm = aux;
    sort(aux.begin(), aux.end());
    int distance = 1;
    while(!equal(aux, perm)){
        distance++;
        next_permutation(aux.begin(), aux.end());
    }
    int val_visible = (visible - 1) % 13;   
    int val_hide = (val_visible + distance) % 13;

    return val_hide + 1 + ((visible - 1) / 13) * 13;
}
