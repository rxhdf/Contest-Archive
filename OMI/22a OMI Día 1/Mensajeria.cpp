#include <bits/stdc++.h>
#include <ios>
#define MAX (int)1e6 + 4
using namespace std;

int N, K;
vector<int> A(MAX, 0);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    for(int i = 1; i <= N; ++i){
        cin >> A[i];
    }
    
    return 0;
}