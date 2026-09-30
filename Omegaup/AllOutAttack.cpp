#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<pair<string, int>> characters(4);
    map<char, vector<int>> monster_power;
    vector<vector<int>> assignments(4);
    vector<int> remaining_attacks(4);
    
    // Leer personajes
    for(int i = 0; i < 4; ++i){
        string powers;
        int energy;
        cin >> powers >> energy;
        characters[i] = {powers, energy};
        remaining_attacks[i] = energy / k;
    }
    
    // Leer enemigos y agrupar por tipo
    for(int i = 1; i <= n; ++i){
        char monster;
        cin >> monster;
        monster_power[monster].push_back(i);   
    }
    
    // Para cada tipo, contar cuántos personajes pueden atacarlo
    map<char, int> char_count;
    for(auto& [tipo, enemigos] : monster_power){
        for(int i = 0; i < 4; ++i){
            if(characters[i].first.find(tipo) != string::npos){
                char_count[tipo]++;
            }
        }
    }
    
    // Ordenar tipos por menor cantidad de personajes que pueden atacarlos
    vector<pair<char, vector<int>>> sorted_monsters;
    for(auto& [tipo, enemigos] : monster_power){
        sorted_monsters.push_back({tipo, enemigos});
    }
    sort(sorted_monsters.begin(), sorted_monsters.end(),
         [&](const auto& a, const auto& b) {
             return char_count[a.first] < char_count[b.first];
         });
    
    // Asignar enemigos (primero los de tipos más restrictivos)
    for(auto& [tipo, enemigos] : sorted_monsters){
        for(int enemy_idx : enemigos){
            bool assigned = false;
            // Intentar asignar a personaje con menos energía restante pero que pueda
            vector<pair<int, int>> candidates; // (remaining_attacks, index)
            for(int i = 0; i < 4; ++i){
                if(characters[i].first.find(tipo) != string::npos && remaining_attacks[i] > 0){
                    candidates.push_back({remaining_attacks[i], i});
                }
            }
            if(candidates.empty()) return 1; // No debería pasar
            
            // Elegir el que tenga mayor remaining_attacks para dejar opciones flexibles
            sort(candidates.begin(), candidates.end(), greater<pair<int, int>>());
            int chosen = candidates[0].second;
            assignments[chosen].push_back(enemy_idx);
            remaining_attacks[chosen]--;
            assigned = true;
        }
    }
    
    for(int i = 0; i < 4; ++i){
        cout << assignments[i].size() << "\n";
        for(int enemy : assignments[i]){
            cout << enemy << " ";
        }
        cout << "\n";
    }
    
    return 0;
}