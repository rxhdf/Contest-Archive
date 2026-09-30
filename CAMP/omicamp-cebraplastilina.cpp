#include <bits/stdc++.h>

using namespace std;

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int mx_len = 1, l_len = 1, r_len = 1, actual = 1;
    for(int i = 1; i < s.length(); ++i){
        if(s[i - 1] != s[i]){
            actual++;
        }else{
            mx_len = max(mx_len, actual);
            actual = 1;
        }
    }
    mx_len = max(actual, mx_len);
    int i = 1, j = s.length() - 2;
    while(s[i] != s[i - 1] && i < s.length()){
        ++i;
        l_len++;
    }
    while(s[j] != s[j + 1]){
        --j;
        r_len++;
    }
    int ans = 0;
    if(s[0] != s[s.length() - 1] && mx_len != s.length()){
        ans = max(l_len + r_len, mx_len);
    }else{
        ans = mx_len;
    }
    cout << ans << "\n";
    return 0;
}