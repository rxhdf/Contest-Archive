#include <bits/stdc++.h>
#include <cstdint>
#define MAX (int)1e5 + 5
using namespace std;

struct Person{
    int born = 0, die = 0, age = 0;
    friend bool operator<(const Person& A, const Person& B){
        return A.born < B.born;
    }
};

int N, Q;
vector<int> A(MAX, 0), B(MAX, 0);
set<int> Querys;
set<Person> People;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> Q;
    for(int i = 1; i <= N; ++i){
        cin >> A[i] >> B[i];
        People.insert({A[i], B[i], (B[i] - A[i])});
    }
    while(Q--){
        int year;
        cin >> year;
        Querys.insert(year);
    }
    //for(auto e: People)cout << e.born << " " << e.die << " " << e.age << "\n";
    for(auto &e: Querys){
        int Oldest = INT32_MIN, youngest = INT32_MAX, Alives = 0;
        auto itr = People.begin();
        while(itr->born <= e && itr->die >= e && itr != People.end()){
            //People.erase(itr);
            Alives++;
            ++itr;
        }
        cout << Alives << "\n";
    }
    return 0;
}