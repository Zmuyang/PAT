#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a,b;
void downAdjust(int l,int h){
	int i(1),j=i*2;
	while(j<=h){
		if(j+1<=h&&b[j]<b[j+1]) j+=1;
		if(b[i]<b[j]){
			swap(b[i],b[j]);
			i=j;
			j=i*2;
		}else break;
	}
}

int main(){
	int n,p(2);
	cin >> n;
	a.resize(n+1);
	b.resize(n+1);
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		cin >> b[i];
	}
	while(p<=n&&b[p-1]<=b[p]) p++;
	int index=p;
	while(p<=n&&a[p]==b[p]) p++;
	if(p==n+1){
		cout << "Insertion Sort" << endl;
		sort(b.begin()+1,b.begin()+index+1);
		cout << b[1];
		for(int i=2;i<=n;i++) cout << " " << b[i];
	}else{
		cout << "Heap Sort" << endl;
		p=n;
		while(p>=2&&b[p]>=b[p-1]) p--;
		swap(b[1],b[p]);
		downAdjust(1,p-1);
		cout << b[1];
		for(int i=2;i<=n;i++){
			cout << " "<<b[i];
		}
	}
	return 0;
}
