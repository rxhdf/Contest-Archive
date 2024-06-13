#include  <bits/stdc++.h>
using namespace std;

stack<int> pila;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    int maximo = 0;
    int actual;
    
    map<int, int> mp;

    cin >> N;
    for(int i =  0; i < N; ++i) {
        int pregunta;
        cin >> pregunta;
        if(pregunta == 1) {
            cin >> actual;
            pila.push(actual);
            if (mp.find(actual) == mp.end())  {
                mp[actual] = 0;
            }
            mp[actual]++;
        }
        else if ( pregunta == 2 ) {
            actual = pila.taop();
            pila.pop();
            mp[actual]--;
            if(mp[actual] == 0) {
                mp.erase(actual);
            }
        }else {
            cout << mp.rbegin()->first <<  endl;
        }
    }
    return 0;
}