#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    map<char, int> mp;
    set<char> aux;
    cin >> s;
    for(int i = 0; i < s.length(); ++i){
        aux.insert(s[i]);
    }
    int k = aux.size();
    int l = 0, r = 0, length = n, uniques = 0;
    for(r = 0; r < n; ++r){
        mp[s[r]]++;
        if(mp[s[r]] == 1)uniques++;
        while(uniques == k){
            length = min(length, r - l + 1);
            mp[s[l]]--;
            if(mp[s[l]] == 0)uniques--;
            l++;
        }
    }
    cout << length << "\n";
    return 0;
}