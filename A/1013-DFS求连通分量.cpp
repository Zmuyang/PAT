/*
	����DFS����ȥ��ĳ�����֮�����ͨ�����ĸ��� cnt��ֻ��Ҫ cnt-1 ���� ���Ϳɱ�Ϊ��ͨͼ 
*/
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX=1010;
int G[MAX][MAX]; //�ڽӾ��� 
int N,M,K;
bool vis[MAX];

void DFS(int u){
	vis[u]=true;
	for(int i=1;i<=N;i++){
		if(vis[i]==false && G[u][i]==1) DFS(i); 
	}
}

int main(){
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0;i<M;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u][v]=1;
		G[v][u]=1;
	}
	for(int i=0;i<K;i++){
		fill(vis,vis+MAX,false);
		int u;
		scanf("%d",&u);
		int cnt=0;
		vis[u]=true;
		for(int j=1;j<=N;j++){
			if(vis[j]==false){
				DFS(j);
				cnt++;
			}
		}
		printf("%d\n",cnt-1);
	}
	return 0;
}
