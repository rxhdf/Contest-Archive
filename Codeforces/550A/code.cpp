#include <bits/stdc++.h>
#include <cstdint>
#include <utility>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    vector<pair<int, int>> type1, type2;
    
    auto typo = [&](int a, int b){
        if(s[a] == 'A' && s[b] == 'B')return 1;
        else if(s[a] == 'B' && s[b] == 'A') return 2;
        return 0;
    };
    
    for(int i = 0; i < s.length() - 1; ++i){
        if(typo(i, i + 1) == 1){
            type1.push_back(make_pair(i, i+1));
        }
        else if(typo(i, i + 1) == 2){
            type2.push_back(make_pair(i, i + 1));
        }
    }

    auto good = [&](pair<int, int> p1, pair<int, int> p2){
        if(p1.first != p2.first && p1.first != p2.second && p2.first != p1.second)return true;
        return false;
    };

    if(!type1.size() || !type2.size()){
        cout << "NO\n";
    }else{
        bool ok = false;
        for(int i = 0; i < type1.size(); ++i){
            for(int j = 0; j < type2.size(); ++j){
                if(good(type1[i], type2[j])){
                    ok = true;
                    break;
                }
            }
        }
        cout << (ok == true? "YES\n": "NO\n");
    }
    return 0;
}