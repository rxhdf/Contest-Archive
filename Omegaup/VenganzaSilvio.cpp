#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    string MB;
    cin >> MB;
    unsigned long long int ans = 1;
    int t;
    for(auto &e: MB){
        t = e - '0';
        ans = (ans * ans) % M;
        if(t == 1){
            ans = (ans * N) % M;
        }
    }
    cout << ans << "\n";
    return 0;
}