#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, BS = 0, WS = 1;
    cin >> N;
    vector<int> A(N + 1, 0);
    for(int i = 1; i <= N; ++i){
        cin >> A[i];
    }
    int Start_zero = 0, Start_one = 0;
    int Sz = 0, So = 1; 
    for(int i = 1; i <= N; ++i){
        if(A[i] != Sz)Start_zero++;
        if(A[i] != So)Start_one++;
        swap(Sz, So);
    }
    cout << min(Start_zero, Start_one) << "\n";
    return 0;
}