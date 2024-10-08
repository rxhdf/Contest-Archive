#include <bits/stdc++.h>
#include <ios>

using namespace std;

int N, D, E;
vector<int> A;

int validate(int low, int high){
    int c = 0;
    for(int i = 1; i <= N; ++i){
        if(A[i] >= low && A[i] <= high)++c;
    }
    return c;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> D;
    int vm = 0;
    A.resize(N + 1);
    for(int i = 1; i <= N; ++i){
        cin >> A[i];
        vm = max(A[i], vm);
    }
    cin >> E;
    int ans = 0;
    for(int i = 1; i <= vm; ++i){
        int low = i - D, high = i + D;
        ans = max(ans, validate(low, high));   
    }
    cout << ans << "\n";
    for(int i = 1; i <= E; ++i){
        ans = 0;
        int C;
        cin >> C;
        for(int j = 1; j <= C; ++j){
            pair<int, int> change;
            cin >> change.first >> change.second;
            A[change.first] = change.second;
        }
        for(int i = 1; i <= vm; ++i){
            int low = i - D, high = i + D;
            ans = max(ans, validate(low, high));   
        }
        cout << ans << "\n";
    }
    return 0;
}