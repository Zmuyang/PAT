#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

const int N=110;

vector<int> G[N];  //树
int h[N]={0};         //各结点所处的层号
int leaf[N]={0};     //存放每层的叶子节点个数
int max_h=0;       //树的最大深度

void BFS();

int main(){
	int n,m;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int parent,k,child;
		cin >> parent >> k;
		for(int j=0;j<k;j++){
			cin >> child;
			G[parent].push_back(child);
		}
	} 
	h[1]=1;   //初始化根节点
	BFS();
	for(int i=1;i<=max_h;i++){
		if(i==1) cout << leaf[i];
		else cout << " " << leaf[i];
	}
	return 0; 
}

void BFS(){
	queue<int> Q;
	Q.push(1);    //将根节点压入队列
	while(!Q.empty()){
		int id = Q.front();  //弹出队首节点
		Q.pop();
		max_h=max(max_h,h[id]);  //更新最大深度
		if(G[id].size()==0){    //判断是否为叶子节点
			leaf[h[id]]++;
		}
		for(int i=0;i<G[id].size();i++){
			h[G[id][i]] = h[id]+1;   //子节点编号为G[id][i]
			Q.push(G[id][i]);   
		}
	}
}
