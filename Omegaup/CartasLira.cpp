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
    int c1 = 0, c2 = 0;
    for(int i = 1; i <= N; ++i){
        if(WS % 2 == 0){
            if(A[i] == 1){
                c1++;
            }
        }
        else if(WS % 2 != 0){
            if(A[i] == 0){
                c1++;
            }
        }
        else if(BS % 2 == 0){
            if(A[i] == 0){
                c2++;
            }
        }else{
            if(A[i] == 1){
                c2++;
            }
        }
        
        BS++;
        WS++;
    }
    cout << min(BS, WS) << "\n";
    return 0;
}