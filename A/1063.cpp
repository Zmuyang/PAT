#include <iostream>
#include <set>
using namespace std;
set<int> arr[51];
void compare(int x,int y){
	int total=arr[y].size(),same(0);
	for(set<int>::iterator it=arr[x].begin();it!=arr[x].end();it++){
		if(arr[y].find(*it)!=arr[y].end()) same++;
		else total++;
	}
	printf("%.1f%%\n",same*100.0/total);
}

int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		for(int j=0;j<k;j++){
			int a;
			cin >>a;
			arr[i].insert(a);
		}
	}
	int q,s1,s2;
	cin >> q;
	for(int i=0;i<q;i++){
		cin >> s1 >> s2;
		compare(s1,s2);
	}
	return 0;
}
