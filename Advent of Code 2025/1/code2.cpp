#include <bits/stdc++.h>
using namespace std;

// cuenta cuántos k en [1..x] cumplen k ≡ target (mod 100)
// target expected in [1..99] ; if target==0 it means 100
long long count_hits(long long x, int target) {
    if (target == 0) target = 100;
    if (target > x) return 0;
    // one at k = target, then every +100
    return 1 + (x - target) / 100;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long pos = 50;      // posición inicial (asegúrate que sea 50 si el enunciado lo indica)
    long long total = 0;

    string s;
    while ( (cin >> s) ) {
        if (s.size() < 2) continue;
        char dir = s[0];
        long long x = stoll(s.substr(1));

        long long hits = 0;
        if (dir == 'R' || dir == 'r') {
            int target = (100 - (int)pos) % 100; // k ≡ target (mod 100), target in 0..99
            hits = count_hits(x, target);
            // actualizar posición final
            pos = (pos + x) % 100;
        } else if (dir == 'L' || dir == 'l') {
            int target = (int)pos % 100; // k ≡ pos (mod 100)
            hits = count_hits(x, target);
            // actualizar posición final (resta)
            pos = (pos - (x % 100)) % 100;
            if (pos < 0) pos += 100;
        } else {
            // ignorar líneas no válidas
            continue;
        }

        total += hits;
    }

    cout << total << "\n";
    return 0;
}
