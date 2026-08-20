#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("tttt");
    vector<string> tateti;
    for(int i = 0; i < 3; ++i){
        string s;
        cin >> s;
        tateti.push_back(s);
    }
    int individual = 0, teams = 0;
    for(int i = 0; i < 3; ++i){
        set<char> st;
        for(int j = 0; j < 3; ++j){
            st.insert({tateti[i][j]});
        }
        if(st.size() == 2)teams++;
        if(st.size() == 1)individual++;
    }
    for(int i = 0; i < 3; ++i){
        set<char> st;
        for(int j = 0; j < 3; ++j){
            st.insert({tateti[j][i]});
        }
        if(st.size() == 2)teams++;
        if(st.size() == 1)individual++;
    }
        set<char> st1, st2;
        for(int i = 0; i < 3; ++i){
            st1.insert(tateti[i][i]);
        }
        if(st1.size() == 2)teams++;
        if(st1.size() == 1)individual++;
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                if(i + j == 2){
                    st2.insert(tateti[i][j]);
                }
            }
        }
        if(st2.size() == 2)teams++;
        if(st2.size() == 1)individual++;
    
    cout << individual << "\n" << teams << "\n";
    return 0;
}