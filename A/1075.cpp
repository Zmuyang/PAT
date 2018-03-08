#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int N,K,M;

struct Node{
	int ID;
	int score[6];
	int sum;
	int solve;
	bool flag;
}node[10010];

int cmp(Node a,Node b){
	if(a.sum!=b.sum) return a.sum>b.sum;
	else if(a.solve!=b.solve) return a.solve>b.solve;
	else return a.ID<b.ID; 
}

void init(){
	for(int i=1;i<=N;i++){
		node[i].ID=i;
		node[i].flag=false;
		node[i].solve=0;
		node[i].sum=0;
		memset(node[i].score,-1,sizeof(node[i].score));
	}
}

int main(){
	cin >> N >> K >> M;
	init();
	vector<int> k(K+1);
	for(int i=1;i<=K;i++) cin >> k[i];
	for(int i=0;i<M;i++){
		int id,index,temp;
		scanf("%d%d%d",&id,&index,&temp);
		if(temp!=-1) node[id].flag=true;
		if(temp==-1&&node[id].score[index]==-1) node[id].score[index]=0;
		if(temp==k[index]&&node[id].score[index]<k[index]) node[id].solve++;
		if(temp>node[id].score[index]) node[id].score[index] = temp;
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=K;j++){
			if(node[i].score[j]!=-1) node[i].sum+=node[i].score[j];
		}
	}
	int r=1;
	sort(node+1,node+1+N,cmp);
	for(int i=1;i<=N&&node[i].flag==true;i++){
		if(i>1&&node[i].sum!=node[i-1].sum){
			r=i;
		}
		printf("%d %05d %d",r,node[i].ID,node[i].sum);
		for(int j=1;j<=K;j++){
			if(node[i].score[j]!=-1){
				printf(" %d",node[i].score[j]);
			}else{
				printf(" -");
			}
		}
		printf("\n");
	}
	return 0;
}
