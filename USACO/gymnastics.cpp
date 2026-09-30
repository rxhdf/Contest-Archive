#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("gymnastics");
    int k, n;
    cin >> k >> n;
    vector<vector<int>> score(k, vector<int>(n));
    vector<vector<int>> score2(k, vector<int>(n));
    
    for(int i = 0; i < k; ++i){
        for(int j = 0; j < n; ++j){
            cin >> score[i][j];
            score2[i][score[i][j] - 1] = j; 
        }
    }
    int pairs = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(i == j)continue;
            int wins = 0;
            for(int aux = 0; aux < k; ++aux){
                if(score2[aux][i] < score2[aux][j])wins++;
            }
            if(wins == k){
                pairs++;
            }
        }
    }
    cout << pairs << "\n";
    return 0;
}