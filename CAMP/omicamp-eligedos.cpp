#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    set<int> A, B;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        A.insert(x);
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; ++i){
        int x;
        cin >> x;
        B.insert(x);
    }
    for(auto a: A){
        for(auto b: B){
            if((A.find(a + b) == A.end()) && (B.find(a + b) == B.end())){
                cout << a << " " << b << "\n";
                exit(0);
            }
        }
    }
    return 0;
}