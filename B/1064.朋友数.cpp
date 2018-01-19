#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cmp(int a,int b){
	return a<b;
}

int main(){
	int N,cnt(0);
	cin >> N;
	vector<int> a(N);
	for(int i=0;i<N;i++){
		string s;
		cin >> s;
		for(int j=0;j<s.length();j++){
			a[i]+=(s[j]-'0');
		}
	}
	sort(a.begin(),a.end(),cmp);
	for(int i=1;i<N;i++){           //使表中元素唯一 
		if(a[cnt]!=a[i]){
			a[++cnt]=a[i];
			continue;
		}
	}
	cout << cnt+1 << endl;
	cout << a[0];
	for(int i=1;i<=cnt;i++){
		cout<< " " << a[i];
	}
	return 0;
}
