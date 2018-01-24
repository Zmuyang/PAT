#include <iostream>
#include <vector>
using namespace std;
struct node{
	int data,next;
}list[100000];
int main(){
	vector<int> v[3];
	int s,a,b,c;
	scanf("%d%d%d",&s,&a,&b);
	for(int i=0;i<a;i++){
		scanf("%d",&c);
		scanf("%d%d",&list[c].data,&list[c].next);
	}
	int S=s;
	while(S!=-1){
		int data = list[S].data;
		if(data<0){
			v[0].push_back(S);
		}else if(data>=0&&data<=b){
			v[1].push_back(S);
		}else{
			v[2].push_back(S);
		}
		S=list[S].next;
	}
	int flag(0);
	for(int i=0;i<3;i++){
		for(int j=0;j<v[i].size();j++){
			if(flag==0){
				printf("%05d %d ",v[i][j],list[v[i][j]].data);
				flag=1;
			}else{
				printf("%05d\n%05d %d ",v[i][j],v[i][j],list[v[i][j]].data);
			}
		}
	}
	printf("-1");
	return 0;
}
