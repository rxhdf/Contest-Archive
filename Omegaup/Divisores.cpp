#include <bits/stdc++.h>
#define MAX 2000000
using namespace std;

short int D[MAX];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
    int N;
	cin >> N;
    for (int i = 1; i < MAX; ++i){
		for (int j = i; j < MAX; j += i){
			++D[j];
        }
	}
	int left = N - 1;
	int right = N + 1;
	while (true){
		if (right < MAX && D[N] == D[right]){
			cout << right << "\n";
			break;
		}
		
		if (left > 0 && D[N] == D[left]){
			cout << left << "\n";
			break;
		}
		--left;
		++right;
	}

	return 0;
}