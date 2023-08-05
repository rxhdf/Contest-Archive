#include <bits/stdc++.h>

using namespace std;

int countCombinations(vector<int>& habitaciones, int P, int index, int current_sum, vector<vector<int>>& memo) {
    if (current_sum == P) {
        return 1;
    }

    if (current_sum > P || index >= habitaciones.size()) {
        return 0;
    }

    if (memo[index][current_sum] != -1) {
        return memo[index][current_sum];
    }

    int includeCurrent = countCombinations(habitaciones, P, index + 1, current_sum + habitaciones[index], memo);
    int excludeCurrent = countCombinations(habitaciones, P, index + 1, current_sum, memo);

    memo[index][current_sum] = includeCurrent + excludeCurrent;
    return memo[index][current_sum];
}

int main() {
    int N, P;
    cin >> N;
    vector<int> habitaciones(N);

    for (int i = 0; i < N; i++) {
        cin >> habitaciones[i];
    }

    cin >> P;

    vector<vector<int>> memo(N, vector<int>(P + 1, -1));
    int combinaciones_posibles = countCombinations(habitaciones, P, 0, 0, memo);
    cout << combinaciones_posibles << endl;

    return 0;
}
