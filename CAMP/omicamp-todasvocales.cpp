#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> k;
    if(k < 25){
        cout << "-1\n";
        exit(0);
    }
    int n = -1;
    for(int i = 5; i <=sqrt(k); ++i){
        if(k % i == 0){
            if(k / i >= 5){
                n = i;
                break;
            }
        }
    }
    if(n == -1){
        cout << "-1";
        exit(0);
    }
    int m = k / n;
    vector<char> vowels = {'a', 'e', 'i', 'o','u'};
    vector<vector<char>> word(n, vector<char>(m));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            word[i][j] = vowels[(i + j) % 5];
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cout << word[i][j];
        }
    }
    return 0;
}