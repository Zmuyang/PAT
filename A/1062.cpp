#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int N,L,H;
struct Node{
	int name;
	int v;
	int t;
	int sum;
	int flag;
}node[100005];

int CMP(Node a,Node b){
	if(a.flag!=b.flag){
		return a.flag<b.flag;
	}else if(a.sum!=b.sum){
		return a.sum>b.sum;
	}else if(a.v!=b.v){
		return a.v>b.v;
	}else{
		return a.name<b.name;
	}
}

int main(){
	scanf("%d%d%d",&N,&L,&H);
	int cnt=N;
	for(int i=0;i<N;i++){
		scanf("%d%d%d",&node[i].name,&node[i].v,&node[i].t);
		node[i].sum=node[i].v +node[i].t;
		if(node[i].v<L || node[i].t<L){
			node[i].flag=5;
			cnt--;
		}else if(node[i].v>=H &&node[i].t>=H){
			node[i].flag=1;
		}else if(node[i].v>=H&&node[i].t<H){
			node[i].flag=2;
		}else if(node[i].v>=node[i].t){
			node[i].flag=3;
		}else{
			node[i].flag=4;
		}
	}
	sort(node,node+N,CMP);
	printf("%d\n",cnt);
	for(int i=0;i<cnt;i++){
		printf("%08d %d %d\n",node[i].name,node[i].v,node[i].t);
	}
	return 0;
}
