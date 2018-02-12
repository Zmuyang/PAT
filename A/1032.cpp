#include <cstdio>
using namespace std;

struct NODE{
	int ID;
	int next;
	bool flag=false;
}node[100010];

int main(){
	int F,S,N;
	scanf("%05d %05d %d",&F,&S,&N);
	for(int i=0;i<N;i++){
		int A,N;
		char c;
		scanf("%05d %c %05d",&A,&c,&N);
		node[A].next=N;
	}
	int p;
	for(p=F;p!=-1;p=node[p].next){
		node[p].flag=true;
	}
	for(p=S;p!=-1;p=node[p].next){
		if(node[p].flag==true){
			break;
		}
	}
	if(p!=-1){
		printf("%05d\n",p);
	}else{
		printf("-1\n");
	}
	return 0;
}
