#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int N;
        cin >> N;
        string S;
        cin >> S;
        int ans = 0;
        stack<int> st;
        st.push(0);
        for(int i = 1; i < N; ++i){
            if(S[i] == '_'){
                if(!st.empty()){
                    int idk = st.top();
                    st.pop();
                    ans += i - idk;
                }else{
                    st.push(i);
                }
            }else if(S[i] == '('){
                st.push(i);
            }else if(S[i] == ')'){
                int idk = st.top();
                st.pop();
                ans += i - idk;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

