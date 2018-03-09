#include <iostream>
#include <queue>
#include <algorithm> 
using namespace std;

const int maxn(110);

struct Node{
	int L;
	int R;
}node[maxn];

bool noRoot[maxn]={false};
int n,num(0);

void print(int id){
	cout << id;
	num++;
	if(num<n) cout << " ";
	else cout << endl;
}

void inOrder(int root){
	if(root==-1) return;
	inOrder(node[root].L);
	print(root);
	inOrder(node[root].R);
}

void BFS(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int index=q.front();
		q.pop();
		print(index);
		if(node[index].L!=-1) q.push(node[index].L);
		if(node[index].R!=-1) q.push(node[index].R);
	}
}

void postOrder(int root){
	if(root==-1) return;
	postOrder(node[root].L);
	postOrder(node[root].R);
	swap(node[root].L,node[root].R);
}

int strTOnum(char x){
	if(x=='-') return -1;
	else{
		noRoot[x-'0']=true;
		return x-'0';
	}
}

int findRoot(){
	for(int i=0;i<n;i++){
		if(noRoot[i]==false){
			return i;
		}
	}
}

int main(){
	char l,r;
	cin >> n;
	getchar();
	for(int i=0;i<n;i++){
		cin >> l >> r;
		getchar();
		node[i].L=strTOnum(l);
		node[i].R=strTOnum(r);
	}
	int root=findRoot();
	postOrder(root);
	BFS(root);
	num=0;
	inOrder(root);
	return 0;
}

