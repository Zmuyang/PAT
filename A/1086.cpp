#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

vector<int> pre,in,post;

void postorder(int root,int inL,int inR){
	if(inL>inR) {
		return ;
	}
	int i=inL;
	while(i<inR&&in[i]!=pre[root]) i++;
	postorder(root+1,inL,i-1);
	postorder(root+1+i-inL,i+1,inR);
	post.push_back(pre[root]);
}

int main(){
	int n;
	cin >> n;
	char str[5];
	stack<int> s;
	for(int i=0;i<n*2;i++){
		cin >>str;
		if(strlen(str)==4){
			int num;
			cin >> num;
			pre.push_back(num);
			s.push(num);
		} else{
			in.push_back(s.top());
			s.pop();
		}
	}
	postorder(0,0,n-1);
	cout << post[0];
	for(int i=1;i<n;i++){
		cout << " " << post[i];
	}
	return 0;
}
