#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--){
        int N;
        cin >> N;
        vector<int> A(N);
        for(auto &e: A)cin >> e;
        bool turn = 0;
        while(A.size() > 1){
            if(!turn){
                int change = min_element(A.begin(), A.end() - 1) - A.begin();
                A[change] = max(A[change], A[change + 1]);
                A.erase(A.begin() + change + 1);
            }else{
                int change = max_element(A.begin() + 1, A.end() - 1) - A.begin();
                A[change - 1] = min(A[change - 1], A[change]);
                A.erase(A.begin() + change);
            }
            turn = !turn;
        }
        cout << A[0] << "\n";
    }

    return 0;
}