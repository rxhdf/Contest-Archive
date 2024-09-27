#include <bits/stdc++.h>
#define MAX (int)1e5 + 3
using namespace std;

int N, Q;
vector<int> A(MAX), B(MAX, 0), C(MAX, 0);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> Q;
    for(int i = 1; i <= N; ++i){
        cin >> A[i];
    }
    bool state = 0;
    if(A[1] <= A[2])state = 1;
    else state = 0;
    for(int i = 2; i < N; ++i){
        if(state){
            if(A[i] <= A[i + 1]){
                continue;
            }else {
                state ^= state;
                B[i + 1] = 1;
            }
        }
        else{
            if(A[i] >= A[i + 1]){
                continue;p
            else{
                state ^= state;
                B[i + 1] = 1;
            }
        }
    }
    for(int i = 1; i <= N; ++i){
        cout << B[i] << " ";
    }
    
    return 0;
}