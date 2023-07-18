#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  long long int n;
  cin >> n;
  vector<int>nu(n);

  for(int i = 0; i < n-1; ++i)
    cin >> nu[i];

  sort(nu.begin(),nu.end());

  for(int i = 0; i < nu.size(); ++i) {
    if (nu[i+1] != nu[i]+1)
        cout << nu[i]+1;
        return 0;
  }
 
  return 0;
}