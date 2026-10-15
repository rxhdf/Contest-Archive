#include "cartas.h"
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


bool equal(vector<int> &a, vector<int> &b){
    for(int i = 0; i < a.size(); ++i){
        if(a[i] != b[i])return false;
    }
    return true;
}

vector<int> asistente(int n, int k, vector<int> a) {

    int sum = 0;
    for(int i = 0; i < k; ++i){
        sum += a[i] - 1;
    }
    int pos = sum % k;
    vector<int> ans;
    for(int i = 0; i < k; ++i){
        if(i != pos){
            ans.push_back(a[i]);
        }
    }
    int p = a[pos] - pos - 1;
    int q = p / k;
    sort(ans.begin(), ans.end());
    int cnt = 0;
    for(int i = 0; i < q; ++i){
        next_permutation(ans.begin(), ans.end());
    }
    return ans;
}

int mago(int n, int k, vector<int> b) {
    vector<int> perm = b;
    sort(b.begin(), b.end());
    int distance = 1;
    while(!equal(b, perm)){
        distance++;
        next_permutation(b.begin(), b.end());
    }
    int sum = 0;
    for(auto e: perm){
        sum += e - 1;
    }

    int aux = -(sum) % k;

    if(aux < 0){
        aux += k;
    }

    int pos = (distance - 1) * k + aux;

    vector<bool> used(n + 1, false);

    for(auto e: perm){
        used[e] = true;
    }
    vector<int> candidates;
    for(int i = 1; i <= n; ++i){
        if(!used[i]){
            candidates.push_back(i);
        }
    }
    return candidates[pos];
}
