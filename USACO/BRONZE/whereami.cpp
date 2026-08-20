#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("whereami");
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 1; i <= n; ++i){
        unordered_map<string, int> subsequences;
        bool solution = true;
        for(int j = 0; j <= n - i; ++j){
            string add = s.substr(j, i);
            subsequences[add]++;
            if(subsequences[add] > 1)solution = false;
        } 
        if(solution){
            cout << i << "\n";
            break;
        }
    }
    return 0;
}