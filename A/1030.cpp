#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX=505,INF=1000000000;
int G[MAX][MAX],C[MAX][MAX],dis[MAX],c[MAX],pre[MAX];
int N,M,S,D;
bool vis[MAX]={false};
void Dijkstra(int s){
	fill(dis,dis+MAX,INF);
	fill(c,c+MAX,INF);
	for(int i=0;i<N;i++){
		pre[i]=i;
	}
	dis[s]=0;
	c[s]=0;
	for(int i=0;i<N;i++){
		int u(-1),MIN=INF;
		for(int j=0;j<N;j++){
			if(vis[j]==false&&dis[j]<MIN){
				u=j;
				MIN=dis[j];
			}
		}
		if(u==-1) return;
		vis[u]=true;
		for(int v=0;v<N;v++){
			if(vis[v]==false&&G[u][v]!=INF){
				if(dis[u]+G[u][v]<dis[v]){
					dis[v]=dis[u]+G[u][v];
					c[v]=c[u]+C[u][v];
					pre[v]=u;
				}else if(dis[u]+G[u][v]==dis[v]){
					if(c[u]+C[u][v]<c[v]){
						c[v]=c[u]+C[u][v];
						pre[v]=u;
					}
				}
			}
		}
	}
}
void DFS(int v){
	if(v==S){
		cout << v << " ";
		return;
	}
	DFS(pre[v]);
	cout << v << " ";
}

int main(){
	cin >> N >> M >> S >> D;
	fill(G[0],G[0]+MAX*MAX,INF);

	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		cin >> G[a][b];
		cin >> C[a][b];
		G[b][a]=G[a][b];
		C[b][a]=C[a][b];
	}
	Dijkstra(S);
	DFS(D);
	printf("%d %d\n",dis[D],c[D]);
	return 0;
}
