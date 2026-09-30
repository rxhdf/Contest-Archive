#include "magos.h"
using namespace std;

int adivinar_sombrero(int n, int i, vector<int> visto) {
    if(i == 1){
        int sum = 0;
        for(auto e: visto){
            sum += e;
        }
        return sum % 3;
    }else{
        int S = visto[0];
        int Pref, Suf;
        Pref = Suf = 0;
        for(int j = 1; j < i - 1; ++j){
            Pref += visto[j];
        }
        for(int j = i - 1; j < visto.size(); ++j){
            Suf += visto[j];
        }
        int ans = (S - Pref - Suf) % 3;
        if(ans < 0){
            ans += 3;
        }
        return ans;
    }

    return 0;
}
