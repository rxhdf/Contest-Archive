#include <bits/stdc++.h>

using namespace  std;

int count(int x){
  int c = 0;
  for(int i = 1; i * i <= x; ++i){
    if(x % i == 0)c += i * i == x ? 1 : 2;
  }
  return c;
}

void solve(){
  int x;  
  cin >> x;
  cout << count(x) << "\n";
}

int main(){
  int T;
  cin >> T;
  while(T--)
    solve();
  return 0;
}
