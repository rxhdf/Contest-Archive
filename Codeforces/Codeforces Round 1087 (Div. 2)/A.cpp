#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while(tt--){
    int n, c, k;
    cin >> n >> c >> k;
    vector<int> a(n);
    for(auto &e: a){
      cin >> e;
    }

    ll anss = 0;
    for(int i = 0; i < n; ++i){

      ll aux = abs(a[i] - c);
      k = max((long long)(k - aux), (long long)(0));


      anss += a[i] + ((k >= 1)? aux: 0);
    }
  }
  cout << anss << "\n";

  return 0;
}
