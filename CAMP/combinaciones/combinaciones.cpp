#include "combinaciones.h"
#include <bits/stdc++.h>

using namespace std;

tuple<int, int, vector<int>> combinar(int n, int k, vector<int> a) {

    vector<int> aa(a);
    if(!aa.empty() && aa[0] == 1){
        aa.erase(aa.begin());
    }else{
        aa.insert(aa.begin(), 1);
    }

    k = aa.size();
    return make_tuple(n, k, aa);
}
