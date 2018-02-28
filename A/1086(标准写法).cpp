#include <iostream>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

const int maxn(50);
struct node{
	int data;
	node* lchild;
	node* rchild;
};

int pre[maxn],in[maxn],post[maxn];
int n;

node* create(int preL,int preR,int inL,int inR){  //根据先序和中序构建出二叉树，并返回根结点地址 
	if(preL>preR){
		return nullptr;
	}
	node* root=new node;
	root->data = pre[preL];
	int k;
	for(k=inL;k<=inR;k++){
		if(in[k]==pre[preL]){
			break;
		}
	}
	int numLeft = k-inL;
	root->lchild=create(preL+1,preL+numLeft,inL,k-1);
	root->rchild=create(preL+numLeft+1,preR,k+1,inR);
	return root;
}

int num(0);
void postorder(node* root){
	if(root==nullptr){
		return;
	}
	postorder(root->lchild);
	postorder(root->rchild);
	cout << root->data;
	num++;
	if(num<n) cout<< " ";
}

int main(){
	cin >> n;
	char str[5];
	stack<int> st;
	int x,preIndex(0),inIndex(0); //入栈元素、先序序列位置、中序序列位置
	for(int i=0;i<2*n;i++){   //出栈入栈共2n次 
		cin >> str;
		if(strcmp(str,"Push")==0){
			cin >> x;
			pre[preIndex++]=x;
			st.push(x);
		}else{
			in[inIndex++]=st.top();
			st.pop();
		}
	} 
	node* root=create(0,n-1,0,n-1);
	postorder(root);
	return 0;
}
