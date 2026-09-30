#include "moebius.h"
#include <bits/stdc++.h>

const long long INF = LLONG_MAX;
// Main
//	long long avanza(long long casas)

bool check(long long origen){
	if(origen > avanza(1))return false;
	return true;
}

void encuentraCasa(long long origen, long long destino) {
	// FIXME
	bool ascendent = check(origen);
	if(origen < destino){
		if(ascendent){
			int l = 1, r = INF;
			while(l < r){
				int mid = l + (r - l) / 2;
				if(avanza(mid) > destino){
					r = mid - 1;
					avanza(-mid);
				}else{
					l = mid;
				}
			}
		}else{

		}
	}else{
		if(ascendent){

		}else{
			
		}
	}
}