#include <bits/stdc++.h>

#define MAXN 100001

using namespace std;

int st[4*MAXN];

struct Infopila{
    int in, end;
};

void update(int start, int end, int node, int index, int val){
    int mid = (start + end) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;
    if(start == end){
        st[node] += val;
        return;
    }else {
        if(start <= index && index <= mid){
            update(start, mid, left, index, val);
        }else {
            update(mid+1, end, right, index, val);
        }
    }
    st[node] = st[left] + st[right];
}
int query(int start, int end, int node, int l, int r){
    int mid = (start + end) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;
    if(start > r || end < l)return 0;
    if(start >= l && end <= r){
        return st[node];
    }
    int c1 = query(start, mid, left, l, r);
    int c2 = query(mid+1, end, right, l, r);
    return (c1 + c2);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int s1, s2;
    cin >> s1 >> s2;
    int u = s1 + s2;
    map<int, int>pos;
    vector<int> a;
    vector<int>a2;
    a.push_back(0);
    for(int i = 1; i <= s1; ++i){
        int h;
        cin >> h;
        a.push_back(h);
    }
    for(int i = 1; i <= s2; ++i){
        int h;
        cin >> h;
        a2.push_back(h);
    }
    for(int i = s2-1; i >= 0; --i){
        a.push_back(a2[i]);
    }
    for(int i = 1; i <= u; ++i){
        pos[a[i]] = i;
    }
    Infopila ab = {1, s1};
    Infopila b = {s1+1, u};
    for(int i = 1; i <= u; ++i){
        if(pos[i] >= ab.in && pos[i] <= ab.end){
            int yaquitamos = query(1, u, 1, pos[i], ab.end);
            int moveremos = ab.end - pos[i] - yaquitamos;
            if(moveremos != 0){
                cout << moveremos << "\n" << "A\n";
            }else{
                cout << "A\n";
            }
            ab.end = pos[i];
            b.in = pos[i];
            update(1, u, 1, pos[i], 1); 
        }
        else if(pos[i] >= b.in && pos[i] <= b.end){
            int yaquitamos = query(1, u, 1, b.in, pos[i]);
            int moveremos = pos[i] - b.in - yaquitamos;
            if(moveremos != 0){
                cout << moveremos*-1 << "\n" << "B\n";
            }else {
                cout << "B\n";
            }
            ab.end = pos[i];
            b.in = pos[i];
            update(1, u, 1, pos[i], 1);    
        }
    }

    return 0;
}