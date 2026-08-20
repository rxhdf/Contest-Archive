#include <bits/stdc++.h> 
using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int q, n;
    cin >> q >> n;
    vector <long long> prefixSum(n, 0);
    long long litros1;
    cin >> litros1;
    prefixSum[0] = litros1;
    for (int i = 1; i < n; i++){
      long long litrosCurrent;
      cin >> litrosCurrent;
      prefixSum[i] += litrosCurrent + prefixSum[i - 1];
    }
    for (int i = 0; i < q; i++){
        long long g;
        cin >> g;
        auto it = upper_bound(prefixSum.begin(), prefixSum.end(), g);
        int indiceOAutosLlenados = it - prefixSum.begin();
        long long gasolinaSobrante = 0;
        if (indiceOAutosLlenados == 0){
            gasolinaSobrante = g;
        } else {
            gasolinaSobrante = g - prefixSum[indiceOAutosLlenados - 1];
        }
        cout << indiceOAutosLlenados << " " << gasolinaSobrante << '\n';
    }
}