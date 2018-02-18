#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
	int address;
	int key;
	int next;
	bool flag;
}node[100000];

int CMP(Node a,Node b){
	if(a.flag==false||b.flag==false){
		return a.flag>b.flag;
	}else{
		return a.key<b.key;
	}
}

int main(){
	int N,Head,cnt(0),a,b,c;
	cin >> N >> Head;
	for(int i=0;i<N;i++){
		cin >> a >> b >> c;
		node[a].address=a;
		node[a].key=b;
		node[a].next=c;
	}
	
	for(int i=Head;i!=-1;i=node[i].next){
		node[i].flag=true;
		cnt++;
	}
	if(cnt==0){
		cout << 0 << " " << -1;
		return 0;
	}
	sort(node,node+100000,CMP);
	printf("%d %05d\n",cnt,node[0].address);
	for(int i=0;i<cnt;i++){
		printf("%05d %d ",node[i].address,node[i].key);
		if(i!=cnt-1){
			printf("%05d\n",node[i+1].address);
		}else{
			printf("-1\n");
		}
	}

	return 0;
}
