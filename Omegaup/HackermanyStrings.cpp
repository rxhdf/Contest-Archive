#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> A(N);
    for(auto &e: A)cin >> e;
    sort(A.begin(), A.end());
    int sz = A[N - 1];
    int nax = A[N - 1];
    map<int, int> mp;
    mp[A[N - 1]]++;
    for(int i = N - 2; i >= 0; --i){
        if(!mp[A[i]]){
            sz += A[i];
            mp[A[i]]++;
            nax = A[i];
        }else{
            if(nax - 1 > 0){
                sz += nax - 1;
                nax--;
                mp[nax]++;
            }
        }
    }

    cout << sz << "\n";
    return 0;
}