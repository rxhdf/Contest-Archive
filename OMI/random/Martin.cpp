//Fuerza bruta TLE - 10pts
#include <bits/stdc++.h>
#include <ios>
#include <numeric>

using namespace std;

int N, K;
vector<int> A;
long long int costo(int start, int target){
    return (A[target] + abs(target - start));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >>  N >> K;
    A.resize(N);
    for(int i = 0; i < N; ++i){
        cin >> A[i];
    }
    for(int i = 0; i < N; ++i){
        vector<int> aux;
        for(int j = 0; j < N; ++j){
            int cost = costo(i, j);
            aux.push_back(cost);
        }
        sort(aux.begin(), aux.end());
        int ans = 0;
        for(int j = 0; j < K; ++j){
            ans += aux[j];
        }
        cout << ans << " ";
    }
    return 0;
}