#include <bits/stdc++.h>
using namespace std;



void merge(vector<int> &arr, int left, int right, int mid){
	int p1 = mid - left + 1;
	int p2 = right - mid;

	vector<int> L(p1), R(p2);

	for(int i = 0; i < p1; ++i){
		L[i] = arr[i + left];
	}
	for(int i = 0; i < p2; ++i){
		R[i] = arr[i + mid + 1];
	}

	int i = 0, j = 0;
	int k = left;
	while(i < p1 && j < p2){
		if(L[i] <= R[j]){
			arr[k] = L[i];
			++i;
		}else{
			arr[k] = R[j];
			++j;
		}
		k++;
	}

	while(i < p1){
		arr[k] = L[i];
		++i;
		++k;
	}
	while(j < p2){
		arr[k] = R[j];
		++j;
		++k;
	}
}

void merge_sort(vector<int> &arr, int left, int right){
	if(left >= right)return;
	int mid = (right + left) / 2;
	merge_sort(arr, left, mid);
	merge_sort(arr, mid + 1, right);
	merge(arr, left, right, mid);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &e: a){
		cin >> e;
	}
	merge_sort(a, 0, n - 1);
	for(auto &e: a){
		cout << e << " ";
	}


	return 0;

}
