#include <bits/stdc++.h>

#define ll unsigned long long
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

struct window{
    int corner1, corner2, corner3, corner4;
};

bool visited[1010];
window windows[1010];
ll ans = 0, n;

bool cubre(int arriba, int abajo){
    int filaBoton = windows[abajo].corner1;
    int columnaBoton = windows[abajo].corner4;
    
    return (windows[arriba].corner1 <= filaBoton && filaBoton <= windows[arriba].corner3 && windows[arriba].corner2 <= columnaBoton && columnaBoton <= windows[arriba].corner4);
}

void closes(int wind){
    if(visited[wind])return;
    visited[wind] = true;

    for(int i = wind + 1; i < n; ++i){
        if(!visited[i] && cubre(i, wind)){
            closes(i);
        }
    }
    ans++;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    
    //leer datos
    cin >> n;
    //N -> cantidad de ventanas
    for(int i = 0; i < n; ++i){
        cin >> windows[i].corner1 >> windows[i].corner2 >> windows[i].corner3 >> windows[i].corner4;
        //R1, S1, R2, S2
    }    


    memset(visited, false, sizeof(visited));

    closes(0);
    cout << ans << "\n";
    return 0;

}