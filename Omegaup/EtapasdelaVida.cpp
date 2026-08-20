#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int l;
    cin >> l;
    if(l >= 0 && l <= 3){
        cout << "BEBE\n";
    }
    else if(l >= 4 && l <= 14){
        cout << "NINO\n";
    }
    else if(l >= 15 && l <= 18){
        cout << "JOVEN\n";
    }   
    else if(l >= 19 && l <= 65){
        cout << "ADULTO\n";
    }else{
        cout << "ADULTO 3RA\n";
    }
    
    return 0;
}