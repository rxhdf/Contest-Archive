#include "stalker.h"
#include <bits/stdc++.h>
using namespace std;

void stalker(long long a, vector<long long> C) {    
    if(C.size()){
        responder(a);
    }else{
        anotar(a + 1, a);
    }
}
