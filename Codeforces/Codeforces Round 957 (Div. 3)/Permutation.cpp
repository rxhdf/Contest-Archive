#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> PERM(int N, int M, int K) {
    vector<int> permutation(N, 0);
    int val = N;
    for(int i = 0; i < N; ++i){
        if(val >= K)permutation[i] = val--;
    }
    for(int i = 0; i < N; ++i){
        if(!permutation[i])permutation[i] = val--;
    }
    return permutation;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int N, M, K;
        cin >> N >> M >> K;
        vector<int> permutation = PERM(N, M, K);
        for (auto i : permutation) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
