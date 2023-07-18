#include <bits/stdc++.h>
using namespace std;

struct node{
	int wat[9];
	vector<int> camino;
}in;

int movs[9][9] = {1, 1, 0, 1, 1, 0, 0, 0, 0,
				  1, 1, 1, 0, 0, 0, 0, 0, 0,
				  0, 1, 1, 0, 1, 1, 0, 0, 0,
				  1, 0, 0, 1, 0, 0, 1, 0, 0,
				  0, 1, 0, 1, 1, 1, 0, 1, 0,
				  0, 0, 1, 0, 0, 1, 0, 0, 1,
				  0, 0, 0, 1, 1, 0, 1, 1, 0,
				  0, 0, 0, 0, 0, 0, 1, 1, 1,
				  0, 0, 0, 0, 1, 1, 0, 1, 1};
bool vis[4][4][4][4][4][4][4][4][4];
queue<node> q;
void visitar(node a){
	vis[a.wat[0]][a.wat[1]][a.wat[2]][a.wat[3]][a.wat[4]][a.wat[5]][a.wat[6]][a.wat[7]][a.wat[8]] = true;
}
bool visited(node a){
	return vis[a.wat[0]][a.wat[1]][a.wat[2]][a.wat[3]][a.wat[4]][a.wat[5]][a.wat[6]][a.wat[7]][a.wat[8]];
}
bool ok(node a){
	for(int i = 0; i < 9; ++i){
		if(a.wat[i] != 3)return false;
	}
	return true;	
}
void solve(){
	q.push(in);
	while(!q.empty()){
		node ac = q.front();
		q.pop();
		if(ok(ac)){
			int n = ac.camino.size();
			for(int i = 0; i < n; ++i){
				cout << ac.camino[i] << " ";
			}
			return;
		}
		node sig = ac;
		for(int i = 0; i < 9; ++i){
			sig = ac;
			for(int j = 0; j < 9 ;++j){
				sig.wat[j] += movs[i][j];
				sig.wat[j] %= 4;
			}
			sig.camino.push_back(i + 1);
			if(!visited(sig)){
				visitar(sig);
				q.push(sig);
			}
		}
	}

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for(int i = 0; i < 9; ++i){
		cin >> in.wat[i];
		in.wat[i] /= 3;
		in.wat[i]--;
	}
	solve();
	return 0;
}