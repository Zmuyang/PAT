#include <iostream> 
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N=110;
vector<vector<int>> G(N) ;   //存放树，邻接表
int leaf[N]={0};   //存放每层叶子节点的个数
int max_h=1; //树的深度

void DFS(int index, int h);

int main(){
	int n,m,parent,child,k;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		cin >> parent >> k;
		for(int j=0;j<k;j++){
			cin >> child;
			G[parent].push_back(child);   //加边
		}
	}
	DFS(1,1);
	cout << leaf[1];
	for(int i=2;i<=max_h;i++){
		cout << " " << leaf[i];
	}
	return 0;
} 
void DFS(int index, int h){  //index为当前遍历到的结点编号， h为当前深度
	max_h=max(max_h,h);
	if(G[index].size()==0){
		leaf[h]++;
		return;
	}
	for(int i=0;i<G[index].size();i++){   //枚举所有子节点
		DFS(G[index][i],h+1);
	}
} 
