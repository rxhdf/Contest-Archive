// Source: https://usaco.guide/general/io

#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int nearest_element(int pos, const vector<int> &a, int target){
    int d1 = 0, idx1 = 0;
    for(int i = pos; i < (int)a.size(); ++i){
        if(a[i] == target){
            idx1 = i;
            break;        
        }
        if(i == a.size() - 1){
            i = -1;
        }
        d1++;
    }
    //cout << d1 << " " << idx1 << "\n";
    int d2 = 0, idx2 = 0;
    int i = pos;
    //cout << i << "\n";
    while(true){
        //cout << i << "\n";
        if(a[i] == target){
            idx2 = i;
            break;
        }
        if(i == 0){
            i = (a.size());
            //cout << i << "\n";
        }
        --i;
        d2++;
    }
    if(d1 > d2){
        return idx2;
    }
    return idx1;
}   

int distance(int i, int j, int n){
    return min(abs(i - j), n - abs(i - j));
}

int main() {
    int tt;
    cin >> tt;
    while(tt--){
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m), pos1, pos2;
        int zeros = 0, ones = 0 , zeros2= 0 , ones2 = 0;
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            if(a[i] == 0){
                zeros++;
                pos1.push_back(i);
            }else{
                ones++;
                pos2.push_back(i);
            }
        }
        for(int j = 0; j < m; ++j){
            cin >> b[j];
            if(b[j] == 0){
                zeros2 = 1;
            }else{
                ones2 = 1;
            }
        }
        if(ones >= ones2 && zeros >= zeros2){ 
            //cout << n << " " << m << endl;
            int actual_pos = 0, cnt = m;
            for(int i = 0; i < m; ++i){
                if(b[i] != a[actual_pos]){
                    if(a[actual_pos] == 0){
                        int aux = actual_pos;
                        actual_pos = nearest_element(actual_pos, a, 1);
                        cnt += distance(actual_pos, aux, n);
                        //cout << actual_pos << "\n";
                    }else{
                        int aux = actual_pos;
                        actual_pos = nearest_element(actual_pos, a, 0);
                        cnt += distance(actual_pos, aux, n);
                        //cout << actual_pos << "\n";
                    }
                }
            }
            cout << cnt << "\n";
        }else{
            cout << "-1\n";
        }
        
    }
}
