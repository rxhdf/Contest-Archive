#include <bits/stdc++.h>

#define MAXN (int)1e4 + 7

using namespace std;

long long int bet = LONG_LONG_MAX, maximo = 0;
bool si_Da (int cantidad, vector<long long int> personas, int horas) {
    int contador = 0;
    int index = 0;
    while( horas > 0 ) {
        while (personas[index] > 0 && horas > 0){
            personas[index] -= cantidad;
            horas--;
        }
        index++;
    }   
    bool o = false;
    for ( int i = 0; i < personas.size(); ++i ) {
        if ( personas[i] > 0 ) {
            o = false;
            break;
        }else {
            o = true;;
        }
    }
    return o;
}

void binary_search(int in, int fin, vector<long long int>personas, int horas){
    while(in <= fin){
        long long int mid = (in + fin) / 2;
        if(si_Da(mid, personas, horas)){
            fin = mid-1;
            bet = min(bet, mid);
        }else {
            in = mid + 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int N, horas;
    cin >> N >> horas;
    vector<long long int> personas(N);
    for(int i = 0; i < N; ++i){
        cin >> personas[i];
        maximo = max(personas[i], maximo);
    }
    binary_search(1, maximo, personas, horas);
    cout << bet << "\n";
    return 0;
}