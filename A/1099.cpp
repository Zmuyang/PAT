#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn(110);
int n,in[maxn],num(0);

struct Node{
	int data;
	int L;
	int R;
}node[maxn];

void inOrder(int root){
	if(root==-1) return;
	inOrder(node[root].L);
	node[root].data=in[num++];
	inOrder(node[root].R);
}

void BFS(int root){
	queue<int> q;
	q.push(root);
	num=0;
	while(!q.empty()){
		int index=q.front();
		q.pop();
		printf("%d",node[index].data);
		num++;
		if(num<n) printf(" ");
		if(node[index].L!=-1) q.push(node[index].L);
		if(node[index].R!=-1) q.push(node[index].R);
	}
}

int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		scanf("%d%d",&node[i].L,&node[i].R);
	}
	for(int i=0;i<n;i++) cin >> in[i];
	sort(in,in+n);
	inOrder(0);
	BFS(0);
	return 0;
}

