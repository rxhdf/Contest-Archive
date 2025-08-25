#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int N;
        cin >> N;
        string s;
        cin >> s;
        vector<int> A;
        for(int i = 0; i < N; ++i){
            A.push_back(s[i] - '0');
        }
        int x = 0;
        for(int i = 0; i < N; ++i){
            x += A[i];
            



        }        

    }
    return 0;
}