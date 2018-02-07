#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;
const int MAX=50;
struct Node{
	int data;
	Node* Lchild;
	Node* Rchild;
}; 

int in[MAX],post[MAX];
int n;
Node* Create(int PL,int PR,int IL,int IR){
	int numL(0),k(0);
	if(PL>PR){
		return NULL;
	}
	Node* root = new Node;
	root->data = post[PR];
	for(k=IL;k<=IR;k++){
		if(in[k]==post[PR]){
			break;
		}
	}
	numL = k-IL;
	root->Lchild = Create(PL,PL+numL-1,IL,k-1);
	root->Rchild = Create(PL+numL,PR-1,k+1,IR);
	return root;
}
int num(0);
void BFS(Node* root){
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node* now =q.front();
		q.pop() ;
		cout << now->data;
		num++;
		if(num<n){
			cout << " ";
		}
		if(now->Lchild!=NULL){
			q.push(now->Lchild);
		}
		if(now->Rchild!=NULL){
			q.push(now->Rchild);
		}
	}
}

int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> post[i];
	}
	for(int i=0;i<n;i++){
		cin >> in[i];
	}
	Node* root=Create(0,n-1,0,n-1);
	BFS(root);
	return 0;
}
