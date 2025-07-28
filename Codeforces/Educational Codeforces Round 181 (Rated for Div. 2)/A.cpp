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
       if (s.size() >= 3) {
            for (int i = 0; i <= (int)s.size() - 3; ++i) {
                if ((s[i] == 'F' && s[i+1] == 'F' && s[i+2] == 'T') || 
                    (s[i] == 'N' && s[i+1] == 'T' && s[i+2] == 'T')) {
                    sort(s.begin(), s.end());
                    reverse(s.begin(), s.end());
                    cout << s << '\n';
                    ok = false;
                    break;
                }
            }
        }
        if(ok)cout << s << "\n";
    }
    
    return 0;
}