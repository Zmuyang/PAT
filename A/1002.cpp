#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
	double a[1001],b[1001],c[1001]={0.0};
	int m,n,cnt(0);
	cin >> m;
	for(int i=0;i<m;i++){
		int x;
		cin >> x;
		cin >> a[x];
		c[x]+=a[x];
	}
	cin >> n;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		cin >> b[x];
		c[x]+=b[x];
	}
	for(int i=0;i<1001;i++){
		if(c[i]!=0.0) cnt++;
	}
	cout << cnt;
	if(cnt!=0) cout << " ";
	cnt-=1;
	for(int i=1000;i>=0;i--){
		if(c[i]!=0.0){
			cout << i << " ";
			printf("%.1f",c[i]);
			if(cnt!=0){
				cout << " ";
				cnt--;
			}
		}
		
	}
	return 0;
} 
