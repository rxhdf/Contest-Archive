//90 points(TLE)
#include<bits/stdc++.h>

using namespace std;

long long int N, X;
char a;
set<long long int> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i <= N; ++i){
        cin >> a >> X;
        if(a == 'i'){
            s.insert(X);
        }
        else if(a == 'd'){
            s.erase(X);
        }
        else if(a == 'q'){
            long long int cnt = 1;
            for(auto e: s){
                if(cnt == X)cout << e << "\n";
                cnt++;
            }
        }
    }    
    return 0;
}