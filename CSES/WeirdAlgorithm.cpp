#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    long long int n;
    cin >> n;
    cout << n << " ";
    while(n > 1){
        if (n % 2 == 0)n/=2;
        else{ n*=3; n++;}
        cout << n << " ";
    }
  return 0;
}