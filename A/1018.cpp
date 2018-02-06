#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int Max=510;
const int INF=1000000000;
int weight[Max],dis[Max],numPath(0);
int N,M,MAX,INDEX,Need=INF,Back=INF;
int G[Max][Max];
vector<int> path,tempPath;
vector<int> pre[Max];
bool vis[Max]={false};

void Dijkstra(int s){
	fill(dis,dis+Max,INF);
	dis[s]=0;
	for(int i=0;i<N;i++){
		int u=-1,MIN=INF;
		for(int j=0;j<=N;j++){
			if(vis[j]==false && dis[j]<MIN){
				u=j;
				MIN=dis[j];
			}
		}
		if(u==-1) return;
		vis[u]=true;
		for(int v=0;v<=N;v++){
			if(vis[v]==false && G[u][v]!=INF){
				if(dis[u]+G[u][v] < dis[v]){
					dis[v]=dis[u]+G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(dis[u]+G[u][v]==dis[v]){
					pre[v].push_back(u);
				}
			}
		}
	}
}

void DFS(int v){
	if(v==0){
		tempPath.push_back(v);
		int need(0),remain(0);
		for(int i=tempPath.size()-1;i>=0;i--){
			int id=tempPath[i];
			if(weight[id]>0){
				remain += weight[id];
			}else{
				if(remain>abs(weight[id])){
					remain -=abs(weight[id]);
				}else{
					need += abs(weight[id]) -remain;
					remain=0;
				}
			}
		}
		if(need<Need){
			Need=need;
			Back = remain;
			path = tempPath;
		}else if(need==Need&&remain<Back){
			Back = remain;
			path = tempPath;
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for(int i=0;i<pre[v].size();i++){
		DFS(pre[v][i]);
	}
	tempPath.pop_back();
}

int main(){
	cin >> MAX >> N >> INDEX >> M;
	for(int i=1;i<=N;i++){
		int x;
		cin >> x;
		weight[i]= x-MAX/2;
	}
	fill(G[0],G[0]+Max*Max,INF);
	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		cin >> G[a][b];
		G[b][a]=G[a][b];
	}
	Dijkstra(0);
	DFS(INDEX);
	cout << Need << " ";
	for(int i=path.size()-1;i>=0;i--){
		cout << path[i];
		if(i>0){
			cout << "->";
		}
	}
	cout << " " << Back;
	return 0;
} 
