#include <bits/stdc++.h>

#define MAXN (int)1e5 + 1
#define ll long long 

using namespace std;

int N, M;
ll A[MAXN], prefix[MAXN], bigbete = -1;
int V, K;

int binarySearch(int x, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (prefix[mid] - prefix[K-1] >= x){
            high = mid - 1;
            bigbete = mid;
        }
        else low = mid + 1;
    }

    return bigbete;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    cin >> A[0];
    prefix[0] = A[0];
    for(int i = 1; i < N; ++i){
        cin >> A[i];
        prefix[i] = prefix[i-1] + A[i];
    }
    cin >> M;
    while(M--){
        cin >> V >> K;
        bigbete = -1;
        binarySearch(V, K, N-1);
        if(bigbete == -1)cout << N << "\n";
        else cout << bigbete << "\n";
    }
    return 0;
}