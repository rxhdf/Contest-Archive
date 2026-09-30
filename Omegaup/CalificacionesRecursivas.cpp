#include <bits/stdc++.h>

using namespace std;

string s;

int average(int rest, int ini, int end){
    int sum = 0, cnt = 0;
    for(int i = ini+1; i < end; i++){
        if(s[i] != '(' && s[i] != ')' && s[i] != ' ' && s[i] != '+'){
            sum += (s[i] - '0');
            s[i] = '+';
            cnt++;
        }
    }
    sum += rest;

    int sec = 0;
    if(rest == 0) sec = (cnt > 0 ? sum / cnt : 0);
    else sec = sum / (cnt + 1);

    return sec;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    getline(cin, s);
    vector<pair<int,int>> pares;
    stack<int> st;
    for(int i = 0; i < (int)s.size(); i++){
        if(s[i] == '(') st.push(i);
        else if(s[i] == ')'){
            int ini = st.top(); st.pop();
            pares.push_back({ini, i});
        }
    }
    sort(pares.begin(), pares.end(), [&](auto &a, auto &b){
        return (a.second - a.first) < (b.second - b.first);
    });
    int ans = 0;
    for(auto [ini, end] : pares){
        ans = average(ans, ini, end);
    }

    cout << ans << "\n";
    return 0;
}
