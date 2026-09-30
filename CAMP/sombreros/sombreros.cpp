#include "sombreros.h"
#include <bits/stdc++.h>

using namespace std;

int adivinar(vector<int> A, int id) {
    long long sum = 0;
    for(auto &e: A){
        sum += e;
    }
    int ans = (id - (sum % 100) + 100) % 100;
    if(ans == 0){
        ans = 100;
    } 
    return ans; 
}
