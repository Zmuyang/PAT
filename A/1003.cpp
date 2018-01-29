#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXV=510;
const int INF=1000000000;
int N , M , start , en , G[MAXV][MAXV] , weight[MAXV]; //G数组保存边权重 ， weight保存点权重；
int dis[MAXV] , w[MAXV] , num[MAXV];      //dis 保存最短距离 ， w 记录最大点权之和 ， num保存最短路径条数
bool visite[MAXV];  //标记已经访问过的点

void Dijkstra(int s);

int main(){
	cin >> N >> M >> start >> en ;
	for(int i=0;i<N;i++){
		cin >> weight[i];
	}
	int u,v;
	fill(G[0], G[0]+MAXV*MAXV, INF);
	for(int i=0;i<M;i++){
		cin >> u >> v;
		cin >> G[u][v];
		G[v][u] = G[u][v];  //无向图是对称矩阵；
	}
	Dijkstra(start);
	cout << num[en] << " " << w[en];
	return 0;
}
void Dijkstra(int s){    //求带权图的单源最短路径算法，求某个点到其余各点的最短路径
	fill(dis,dis+MAXV,INF);  //按单元初始化数组
	memset(num,0,sizeof(num)); // 按字节初始化数组
	memset(w,0,sizeof(w));
	dis[s]=0;   //起点最短距离设置为0
	w[s]=weight[s];
	num[s]=1;
	for(int i=0;i<N;i++){
		int u=-1 , MIN=INF;
		for(int j=0;j<N;j++){
			if(visite[j]==false && dis[j]<MIN){
				u=j;
				MIN=dis[j];
			}
		}

		if(u==-1) return ;  // u 是用来判断是否访问了所有与起点相连的顶点，若u为-1，表明相关点已经遍历完

		visite[u]=true;
		for(int x=0;x<N;x++){
			if(visite[x]==false && G[u][x]!=INF){
				if(dis[u]+G[u][x]<dis[x]){     //判断加x点后 距离是否变小
					dis[x] = dis[u] + G[u][x];
					w[x] = w[u]+weight[x];
					num[x]=num[u];
				}else if(dis[u] + G[u][x] == dis[x]){  //找到相同长度路径
					if(w[u]+weight[x]>w[x]){
						w[x] = w[u] + weight[x];
					}
					num[x]+=num[u];
				}
			}
		}
	}
}

