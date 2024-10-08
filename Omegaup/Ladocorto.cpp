#include <bits/stdc++.h>
#include <cmath>
#include <cstddef>
#include <iomanip>
#include <ios>

using namespace std;

struct Cord{
    double x, y;
};

Cord a, b, c, d;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
    //Distance for A->B, A->C
    double AB = (pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
    double AC = (pow((a.x - d.x), 2) + pow((a.y - d.y), 2));
    double resB = sqrt(AB);
    double resC = sqrt(AC);
    //Distance for D->B, D->C
    double DB = (pow((c.x - d.x), 2) + pow((c.y - d.y), 2));
    double DC = (pow((c.x - b.x), 2) + pow((c.y - b.y), 2));
    double dresB = sqrt(DB);
    double dresC = sqrt(DC);

    cout << setprecision(9) << min(resB, min(resC, min(dresB, dresC))) << "\n";
    return 0;
}