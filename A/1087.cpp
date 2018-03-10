#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn(210);
const int INF(1000000000);

int n,k,G[maxn][maxn],weight[maxn];
int num[maxn],dis[maxn],point[maxn],w[maxn],pre[maxn];
map<string,int> City;
map<int,string> Index;
bool vis[maxn];

void Dijkstra(int s){
	fill(dis,dis+maxn,INF);
	memset(num,0,sizeof(num));
	memset(point,0,sizeof(point));
	memset(w,0,sizeof(w));
	for(int i=0;i<n;i++) pre[i]=i;
	dis[s]=0;
	num[s]=1;
	for(int i=0;i<n;i++){
		int u(-1),MIN(INF);
		for(int j=0;j<n;j++){
			if(vis[j]==false&&dis[j]<MIN){
				u=j;
				MIN=dis[j];
			}
		}
		if(u==-1) return;
		vis[u]=true;
		for(int v=0;v<n;v++){
			if(vis[v]==false&&G[u][v]!=INF){
				if(dis[u]+G[u][v]<dis[v]){
					dis[v]=dis[u]+G[u][v];
					num[v]=num[u];
					point[v]=point[u]+1;
					pre[v]=u;
					w[v]=w[u]+weight[v];
				}else if(dis[u]+G[u][v]==dis[v]){
					num[v]+=num[u];
					if(w[u]+weight[v]>w[v]){
						w[v]=w[u]+weight[v];
						pre[v]=u;
						point[v]=point[u]+1;
					}else if(w[u]+weight[v]==w[v]){
						double uAvg=1.0*(w[u]+weight[v])/(point[u]+1);
						double vAvg=1.0*w[v]/point[v];
						if(uAvg>vAvg){
							point[v]=point[u]+1;
							pre[v]=u;
						} 
					}
				}
			}
		}
	}
}

void PrintPath(int v){
	if(v==0){
		cout << Index[v];
		return;
	}
	PrintPath(pre[v]);
	cout << "->" << Index[v];
}

int main(){
	string start,city1,city2;
	cin >> n >> k >> start;
	City[start]=0;
	Index[0]=start;
	weight[0]=0;
	fill(G[0],G[0]+maxn*maxn,INF);
	for(int i=1;i<=n-1;i++){
		cin >> city1 >> weight[i];
		City[city1]=i;
		Index[i]=city1;
	}
	for(int i=0;i<k;i++){
		cin >> city1 >> city2;
		int c1=City[city1];
		int c2=City[city2];
		cin >> G[c1][c2];
		G[c2][c1]=G[c1][c2];
	}
	Dijkstra(0); //Ï¸ÐÄ 
	int rom=City["ROM"];
	printf("%d %d %d %d\n",num[rom],dis[rom],w[rom],w[rom]/point[rom]);
	PrintPath(rom);
	return 0;
} 
