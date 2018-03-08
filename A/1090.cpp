#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const int maxn=100010;
vector<int> child[maxn];
double p,r;

int N,maxDepth(0),num(0);

void DFS(int index,int depth){
	if(child[index].size()==0){
		if(depth>maxDepth){
			maxDepth=depth;
			num=1;
		}else if(depth==maxDepth){
			num++;
		}
		return ;
	}
	for(int i=0;i<child[index].size();i++){
		DFS(child[index][i],depth+1);
	}
}

int main(){
	int F,root;
	cin >> N >> p >> r;
	r/=100;
	for(int i=0;i<N;i++){
		scanf("%d",&F);
		if(F!=-1){
			child[F].push_back(i);
		}else root=i;
	}
	DFS(root,0);
	printf("%.2f %d\n",p*pow(1+r,maxDepth),num);
	return 0;
}
