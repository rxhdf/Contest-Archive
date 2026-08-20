#include <bits/stdc++.h>
#define ll long long
using namespace std;


// tipo 1: coordenadas (x, y) -> numero d
ll get_val(int n, ll x, ll y){
    if(n == 0)return 1;
    
    ll half = 1LL << (n - 1); //mitad del lado
    ll area = 1LL << (2LL * n - 2); //area de un cuadrante (4^(n-1))
    
    if(x <= half && y <= half){ //top-left (Orden 0)
        return 0 * area + get_val(n - 1, x, y);
    }else if (x > half && y > half){ //bottom-right (Orden 1)
        return 1 * area + get_val(n - 1, x - half, y - half);
    }else if (x > half && y <= half){ //bottom-left (Orden 2)
        return 2 * area + get_val(n - 1, x - half, y);
    }else{ //top-right (Orden 3)
        return 3 * area + get_val(n - 1, x, y - half);
    }
}

//tipo 2: Numero d -> coordenadas (x, y)
pair<ll, ll> get_pos(int n, ll d){
    if(n == 0)return {1, 1};
    
    ll half = 1LL << (n - 1);
    ll area = 1LL << (2LL * n - 2);
    
    //Determinar en que cuadrante esta d (0 a 3)
    ll cuadrante = (d - 1) / area;
    ll pos = (d - 1) % area + 1;
    
    pair<ll, ll> p = get_pos(n - 1, pos);
    
    if(cuadrante == 0)return {p.first, p.second};//TL
    if(cuadrante == 1)return {p.first + half, p.second + half};//BR
    if(cuadrante == 2)return {p.first + half, p.second};//BL
    return {p.first, p.second + half};//TR(idx == 3)
}

void solve(){
    int n, q;
    cin >> n >> q;
    while(q--){
        string type;
        cin >> type;
        if(type == "->"){
            ll x, y; 
            cin >> x >> y;
            cout << get_val(n, x, y) << "\n";
        }else{
            ll d; 
            cin >> d;
            pair<ll, ll> res = get_pos(n, d);
            cout << res.first << " " << res.second << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt; 
    cin >> tt;
    while(tt--) 
        solve();
    return 0;
}