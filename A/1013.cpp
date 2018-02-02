#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int mat = 1111;
vector<int> G[mat]; //аз╫с╠М
bool vis[mat];
int CurrentDel;

void DFS(int v); 

int main(){
	int n,m,k;
	cin >> n >> m >> k;
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int x=0;x<k;x++){
		cin >> CurrentDel;
		memset(vis,false,sizeof(vis));
		int block(0);
		for(int i=1;i<=n;i++){
			if(i!=CurrentDel && vis[i]==false){
				DFS(i);
				block++;
			}
		}
		cout << block-1 << endl;
	}
	return 0;
}
void DFS(int v){
	if(v==CurrentDel){
		return;
	}
	vis[v]=true;
	for(int i=0;i<G[v].size();i++){
		if(vis[G[v][i]]==false){
			DFS(G[v][i]);
		}
	}
}
