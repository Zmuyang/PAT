#include <iostream>
#include <algorithm>
using namespace std;
int n,weight[1003],CBT[1003],index(0);
void inorder(int root){
	if(root>n){
		return;
	}
	inorder(root*2);
	CBT[root]=weight[index++];
	inorder(root*2+1);
}

int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> weight[i];
	}
	sort(weight,weight+n);
	inorder(1);
	for(int i=1;i<=n;i++){
		cout << CBT[i];
		if(i<n) cout << " ";
	}
	return 0;
}
