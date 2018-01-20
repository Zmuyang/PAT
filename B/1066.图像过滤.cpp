#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int m,n,L,R,t;
	cin >> m >> n >> L >> R >> t;
	int a[m][n];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin >> a[i][j];
			if(a[i][j]>=L && a[i][j]<=R){
				a[i][j] = t;
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(j!=0){
				printf(" %03d",a[i][j]); 
			}else {
				printf("%03d",a[i][j]); 
			}
		}
		cout << '\n';
	}
	return 0;
} 
