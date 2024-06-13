#include <bits/stdc++.h>

using namespace std;

int N, H, B, optimo = INT32_MAX;
int A[100010];


unsigned long long int compra(){
	unsigned long long int costo=0;
	if(optimo==INT_MAX) optimo=H;
	for(int i = 1;i <= N; i++){
		if(A[i]<optimo){
			costo+=((optimo-A[i])*i);
		}
	}
	return costo;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N >> H >> B;
    for(int i = 0; i < N; ++i)cin >> A[i];
    cout << compra() << "\n";

    return 0;
}