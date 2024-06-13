#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll N, X, Y, C, low = 1, high = 50001, mid = 0;

ll fuera_arriba(){
    int arriba = Y - mid;
    if(arriba > 0)return 0;
    return pow(abs(arriba), 2);
}
ll fuera_abajo(){
    int abajo = N - (Y + mid);
    if(abajo > 0)return 0;
    return pow(abs(abajo), 2);
}
ll fuera_izq(){
    int izq = X - mid;
    if(izq > 0)return 0;
    return pow(abs(izq), 2);
}
ll fuera_der(){
    int der = N - (X + mid);
    if(der > 0)return 0;
    return pow(abs(der), 2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> X >> Y >> C;
    while(low <= high){
        mid = (low + high) / 2;
        ll Z = pow(mid-1, 2) + pow(mid, 2);
        Z -= (fuera_der() + fuera_izq() + fuera_abajo() + fuera_arriba());
        if(Z <= C){
            low = mid + 1;
        }else {
            high = mid - 1;
        }
        cout << Z << " " << low << " " << mid << " " << high << "\n";
    }
    cout << low << " " << mid << " " << high << "\n";
  
    return 0;
}