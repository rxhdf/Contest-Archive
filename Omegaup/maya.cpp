#include <bits/stdc++.h>
using namespace std;

int main() {
        int N;
        string S;
        cin >> N;
        cin >> S;
        int zeros = 0, ones = 0;
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            if(S[i] == '0') {
                if(!ones){
                    ans++;
                    zeros++;
                }else{
                    ones--;
                    zeros++;
                }
            }else{
                if(!zeros){
                    ans++;
                    ones++;
                }else{
                    zeros--;
                    ones++;
                }
            }
        }
        cout << ans << endl;

        return 0;
    
}
 
 