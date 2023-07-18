#include <bits/stdc++.h>

#define MAXN 1000002

using namespace std;

int N, M,  L = 0, C = 0, betelguese = 0;
char A[MAXN];

void pancracio(int low, int high){
    int mid = (low + high) / 2;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (A[mid] == 'M'){
            low = mid + 1;
            betelguese = high - mid;
        }
        else high = mid - 1;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; ++i){
        int r;
        cin >> r;
        A[r] = 'R';
        L = max(L, r);
    }
    cin >> M;
    for(int j = 0; j < M; ++j){
        int m, k;
        cin >> k >>m;
        A[k] = 'M';
        L = max(L, k);
        C += m;
    }
    if(C <  N){
        cout << "-1\n";
        return 0;
    }

    return 0;
}