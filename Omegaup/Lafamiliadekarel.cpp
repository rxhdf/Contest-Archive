#include <bits/stdc++.h>

using namespace std;

int N;
map<int, int> tree;

int depth(int V){
    int ans = 0;
    while(tree[V] != V){
        V = tree[V];
        ans++;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    int karel;
    cin >> karel;
    tree[0] = karel;
    for(int i = 1; i <= N; ++i){
        cin >> karel;
        tree[i] = karel;
    }    
    int cmp = depth(0);
    int ans = 0;
    for(int i = 1; i <= N; ++i){
        if(depth(i) == cmp){
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}