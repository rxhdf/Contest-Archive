#include <bits/stdc++.h>
using namespace std;

int bb(const vector<int>& vec, int objetivo) {
    int izquierda = 0;
    int derecha = vec.size() - 1;

    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        if (vec[medio] == objetivo) {
            return medio; // regresa el indice
        }
        if (vec[medio] < objetivo) {
            izquierda = medio + 1; // Buscar en la derecha
        } else {
            derecha = medio - 1;   // Buscar en la izquierda
        }
    }

    return -1; // No se encontró
}

int main() {
    int n, b;

 
    cin >> n;
    vector<int> numeros;
    for (int i = 0; i < n; i++) {
        int valor;
        cin >> valor;
        numeros.push_back(valor); // ya guarde los numeros en vector
    }
    // menos a mas
    sort(numeros.begin(), numeros.end());

    //leer cantdad de numeros a busscar y cuales son
    cin >> b;
    vector<int> busqueda;
    for (int z = 0; z < b; z++) {
        int valor;
        cin >> valor;
        busqueda.push_back(valor);//agregamos al vector segindo
    }

    
    for (int z = 0; z < b; z++) {
        int objetivo = busqueda[z];
        int resultado = bb(numeros, objetivo);

        if (resultado != -1) {
            cout <<" SI esta en el indice " <<endl;
        } else {
            cout << "xd"<<endl;
        }
    }

    return 0;
}