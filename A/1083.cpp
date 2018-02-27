#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
	string name;
	string ID;
	int grade;
}node[1000];

int cmp(Node a,Node b){
	return a.grade>b.grade;
}

int main(){
	int n,L,R;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> node[i].name >> node[i].ID >> node[i].grade;
	}
	cin >> L >> R;
	sort(node,node+n,cmp);
	int cnt(0);
	for(int i=0;i<n;i++){
		if(node[i].grade>=L&&node[i].grade<=R){
			cout << node[i].name << " " << node[i].ID << endl;
			cnt++;
		}
	}
	if(cnt==0){
		cout << "NONE" << endl;
	}
	return 0;
}
