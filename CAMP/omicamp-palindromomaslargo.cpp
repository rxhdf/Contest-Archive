#include <bits/stdc++.h>

using namespace std;

bool palindrome(string a, string b){
  reverse(b.begin(), b.end());
  return a == b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> inicio, fin;
    vector<string> cadenas;
    vector<bool> used(n, false);
    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;
        cadenas.push_back(s);
    }
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            if(palindrome(cadenas[i], cadenas[j]) && !used[i]){
                inicio.push_back(cadenas[i]);
                fin.push_back(cadenas[j]);
                used[i] = true;
                break;
            }
        }
    }
    string izquierda, derecha, centro;
    izquierda = derecha = centro = "";

    for(int i = 0; i < inicio.size(); ++i){
        izquierda += inicio[i];
    }
    for(int j = 0; j < cadenas.size(); ++j){
        if(!used[j] && palindrome(cadenas[j], cadenas[j])){
            centro = cadenas[j];
            break;
        }
    }
    for(int i = fin.size() - 1; i >= 0; --i){
        derecha += fin[i];
    }
    cout << (izquierda.size() + centro.size() + derecha.size()) << "\n";
    cout << izquierda + centro + derecha << "\n";
    return 0;
}