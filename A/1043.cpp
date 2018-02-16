#include <iostream>
#include <vector>
using namespace std;

vector<int> pre;
vector<int> post;

bool flag;  //判断是否为镜面线索二叉树 

void getPost(int root,int tail){
	if(root>tail){
		return;
	}
	int i=root+1,j=tail;
	if(!flag){     //非镜面线索二叉树，进行后序排序 
		while(i<=tail && pre[root]>pre[i]) i++;
		while(j>root && pre[root]<=pre[j]) j--;
	}else{
		while(i<=tail && pre[root]<=pre[i]) i++;
		while(j>root && pre[root]>pre[j]) j--;
	}
	if(i-j!=1){
		return ;
	}
	getPost(root+1,j);
	getPost(i,tail);
	post.push_back(pre[root]);
}

int main(){
	int N;
	cin >> N;
	pre.resize(N); 
	for(int i=0;i<N;i++){
		scanf("%d",&pre[i]);
	}
	getPost(0,N-1);
	if(post.size()!=N){   //非先序排序，进行镜面后序 
		flag=true;
		post.clear();
		getPost(0,N-1);
	}
	if(post.size()==N){   //若后序长度于原长度相等 
		cout << "YES" << endl;
		for(int i=0;i<N;i++){
			if(i==0){
				cout << post[0];
			}else{
				cout << " " << post[i];
			}
		}
	}else{
		cout << "NO";
	}
	return 0;
}
