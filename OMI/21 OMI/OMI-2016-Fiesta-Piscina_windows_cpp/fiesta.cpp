#include "fiesta.h"
#include <bits/stdc++.h>

// Main
//	int Preguntar(int a, int b)

int BusquedaCool(int n) {
	// FIXME
	int candidate = 1;
    for (int i = 2; i <= n; ++i) {
        if(Preguntar(candidate, i)) {
            candidate = i;
        }
    }

    for (int j = 1; j <= n; ++j) {
		if(j == candidate)continue;
		if(Preguntar(candidate, j) || !Preguntar(j, candidate))return 0;
	}

    return candidate;
}