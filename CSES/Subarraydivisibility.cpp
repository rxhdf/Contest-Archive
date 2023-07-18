#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;

int main(){
    ll N;
    cin >> N;
    ll ans = 0;
    vector<int> A(N + 1, -1);
    A[0] = 0;
    ll ac = 0;
    for(int i = 1; i <= N; ++i){
        int u;
        cin >> u;
        ac = (((ac + u) % N) + N )%N;
          
        ans += ++A[ac];
    }
    cout << ans;
}