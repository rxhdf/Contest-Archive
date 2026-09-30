#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        string s;
        cin >> s;
        bool ok = true;
        if(s[s.length() - 1] != 'B'){
            ok = false;
        }else{
            long long cnt = 0;
            for(char c : s){
                if(c == 'A')cnt++;
                else{
                    if (cnt == 0){
                        ok = false;
                        break;
                    }
                    cnt--;
                }
            }
        }
        if(ok){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

    return 0;
}