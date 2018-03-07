#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn(1020);
const int INF(1000000000);
int N,M,K,D;
int G[maxn][maxn],dis[maxn];
bool vis[maxn];

void dijkstra(int x){
	memset(vis,false,sizeof(vis));
	fill(dis,dis+maxn,INF);
	dis[x]=0;
	for(int i=0;i<=N+M;i++){
		int u(-1),MIN(INF);
		for(int j=1;j<=N+M;j++){
			if(vis[j]==false && dis[j]<MIN){
				u=j;
				MIN=dis[j];
			}
		}
		if(u==-1) return;
		vis[u]=true;
		for(int v=1;v<=M+N;v++){
			if(vis[v]==false && G[u][v]!=INF){
				if(dis[v]>dis[u]+G[u][v]){
					dis[v]=dis[u]+G[u][v];
				}
			}
		}
	}
}

int getID(string S){
	int i(0),index(0);
	while(i<S.length()){
		if(S[i]!='G'){
			index=index*10+(S[i]-'0');
		}
		i++;
	}
	if(S[0]=='G') return N+index;
	else return index;
} 

int main(){
	int u,v,w;
	char c1[5],c2[5];
	cin >> N >> M >> K >> D;
	fill(G[0],G[0]+maxn*maxn,INF);
	for(int i=0;i<K;i++){
		scanf("%s%s%d",c1,c2,&w);
		u=getID(c1);
		v=getID(c2);
		G[u][v]=G[v][u]=w;
	}
	
	double DIS(-1),AVG(INF);
	int id(-1);
	
	for(int i=N;i<=N+M;i++){
		double mindis(INF),avg(0);
		dijkstra(i);
		for(int j=1;j<=N;j++){
			if(dis[j]>D){
				mindis=-1;
				break;
			}
			if(dis[j]<mindis){
				mindis=dis[j];
			}
			avg+=1.0*dis[j]/N;
		}
		if(mindis==-1) continue;
		if(mindis>DIS){
			DIS=mindis;
			id=i;
			AVG=avg;
		}else if(mindis==DIS&&avg<AVG){
			AVG=avg;
			id=i;
		}
	}
	if(id==-1) cout << "No Solution" << endl;
	else{
		cout <<'G'<< id-N << endl;
		printf("%.1f %.1f\n",DIS,AVG);
	}
	return 0;
}
