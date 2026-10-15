#include <bits/stdc++.h>

using namespace std;

bool check(int n, int x, vector<int> &A){
    int pivote = n - 1; 
    //buscar pareja de 11 o 00 mas cercana al centro

    for(int i = 0; i < n - 1; ++i){
        bool left = ((pivote - i - 1 >= 0)&& ((A[pivote - i] >= x) == (A[pivote - i - 1] >= x)));
        bool right = ((pivote + i + 1 < A.size()) && ((A[pivote + i] >= x) == (A[pivote + i + 1] >= x)));
        if(left){
            return (A[pivote - i] >= x);
        }
        if(right){
            return (A[pivote + i] >= x);
        }
    }
    return A[0] >= x;
}

void solve1(){
    int n, x;
    cin >> n >> x;
    int longitud = (2 * n) - 1;
    if(x == 1 || x == longitud){
        cout << "NO\n";
        return;
    }
    cout << "SI\n";
    if(x < ((longitud / 2) + 1)){
        vector<int> A, B;
        for(int i = 1; i <= longitud / 2; ++i){
            A.push_back(i);
        }
        int pivote = (longitud / 2) +  1; 
        for(int i = (longitud / 2) + 2; i <= longitud; ++i){
            B.push_back(i);
        }
        swap(pivote, A[x - 1]);
        sort(A.rbegin(), A.rend());
        for(int i = 0; i < A.size(); ++i){
            cout << A[i] << " ";
        }
        cout << pivote << " ";
        for(int i = 0; i < B.size(); ++i){
            cout << B[i] << " ";
        }
        cout << "\n"; 
    }
    else if(x > ((longitud / 2) + 1)){
        vector<int> A, B;
        for(int i = 1; i <= longitud / 2; ++i){
            A.push_back(i);
        }
        int pivote = (longitud / 2) +  1; 
        for(int i = (longitud / 2) + 2; i <= longitud; ++i){
            B.push_back(i);
        }
        swap(pivote, B[x - 1 - n]);
        sort(B.rbegin(), B.rend());
        for(int i = 0; i < A.size(); ++i){
            cout << A[i] << " ";
        }
        cout << pivote << " ";
        for(int i = 0; i < B.size(); ++i){
            cout << B[i] << " ";
        }
        cout << "\n"; 
    }else{
        for(int i = 1; i <=longitud; ++i){
            cout << i << " ";
        }
        cout << "\n";
    }
}
void solve2(){
    int n;
    cin >> n;
    vector<int> A((2 * n) - 1);
    for(int i = 0; i < (int)A.size(); ++i){
        cin >> A[i];
    }
    //busqueda binaria
    int l = 1, r = 2 * n - 1, ans = 0;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(check(n, mid, A)){
            l = mid + 1;
            ans = mid;
        }else{
            r = mid - 1;
        }
    }
    cout << ans << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, s;
    cin >> tt >> s;
    while(tt--){
        if(s == 1){
            //dejar x hasta arriba
            solve1();        
        }else{
            //que x queda hasta arriba
            solve2();
        }
    }

    return 0;
}