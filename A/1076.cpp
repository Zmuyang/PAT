#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int maxn(1010);
struct Node{
	int ID;
	int lev;
};

vector<Node> Adj[maxn]; //邻接表 
bool inq[maxn]={false}; //顶点是否已经加入过队列

int BFS(int s,int L){  //起始节点和层数上限 
	int numForward=0; //转发数
	queue<Node> q;	//BFS队列 
	Node start;   //定义起始结点 
	start.ID=s;		//起始结点编号 
	start.lev=0;	//起始节点层号为0 
	q.push(start);   //将起始节点压入队列 
	inq[start.ID]=true;  //起始结点的编号设为已被加入过队列 
	while(!q.empty()){   
		Node top=q.front();
		q.pop();
		int u=top.ID;  //队首节点的编号 
		for(int i=0;i<Adj[u].size();i++){
			Node next=Adj[u][i];		//从u出发能到达的结点 next 
			next.lev=top.lev+1;			
			if(inq[next.ID]==false&&next.lev<=L){
				q.push(next);
				inq[next.ID]=true;
				numForward++;
			}
		}
	} 
	return numForward;
}

int main(){
	Node user;
	int N,L,numFollow,idFollow;
	cin >> N >> L;
	for(int i=1;i<=N;i++){
		user.ID=i;
		scanf("%d",&numFollow);
		for(int j=0;j<numFollow;j++){
			scanf("%d",&idFollow);
			Adj[idFollow].push_back(user);
		}
	}
	int numQuery,s;
	cin >> numQuery;
	for(int i=0;i<numQuery;i++){
		memset(inq,false,sizeof(inq));
		scanf("%d",&s);
		int numForward=BFS(s,L);
		printf("%d\n",numForward);
	}
	return 0;
} 
