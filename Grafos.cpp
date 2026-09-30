#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    //n -> Cantidad de nodos
    //m -> Cantidad de aristas o conexiones

    cin >> n >> m;
    /*
    //Matriz de adyacencia
    vector<vector<int>> matriz(n, vector<int>(n, 0));
    
    for(int i = 0; i < m; ++i){
        //A, B -> una conexion entre los nodos A y B
        int a, b;
        cin >> a >> b;
        matriz[a][b] = 1;
        matriz[b][a] = 1;
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << matriz[i][j] << " ";
        }
        cout << "\n";
    }
    */

    //Lista de adyacencia
    /*
    vector<vector<int>> lista_adyacencia(n);
    for(int i = 0; i < m; ++i){
        //A, B -> una conexion entre los nodos A y B
        int a, b;
        cin >> a >> b;
        lista_adyacencia[a].push_back(b);
        lista_adyacencia[b].push_back(a);
    }

    for(int i = 0; i < n; ++i){
        cout << "Nodo " << i << " relacionado con: ";
        for(int j = 0; j < lista_adyacencia[i].size(); ++j){
            cout << lista_adyacencia[i][j] << ' ';
        }
        cout << "\n";
    }
    */
    
    vector<pair<int, int>> lista_aristas(m);

    for(int i = 0; i < m; ++i){
        cin >> lista_aristas[i].first >> lista_aristas[i].second;
        //.first representa nodo A
        //.second representa nodo B
    }

    for(int i = 0; i < m; ++i){
        cout << lista_aristas[i].first << " " << lista_aristas[i].second << "\n";
    }
    return 0;
}
//(i, j) - conexion entre los nodos i,j