#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int cmp(int a,int b){
	return a>b;
}
int Func(int N){
	int i=sqrt(N);
	while(i>=1){
		if(N%i==0){
			return i;
		}
		i--;
	}
	return 1;
}
int main(){
	int N,m,n;
	cin >> N;
	int cnt(0);
	n=Func(N); //n是列 
	m=N/n;   // m是行
	vector<int> a(N);
	for(int i=0;i<N;i++) cin >> a[i];
	vector<vector<int>>  b(m,vector<int>(n));
	sort(a.begin(),a.end(),cmp);
	int level = m/2+m%2;
	for(int i=0;i<level;i++){
		for(int j=i;j<=n-1-i&&cnt<=N-1;j++) b[i][j]=a[cnt++];
		for(int j=i+1;j<=m-2-i&&cnt<=N-1;j++) b[j][n-1-i]=a[cnt++];
		for(int j=n-i-1;j>=i&&cnt<=N-1;j--) b[m-1-i][j]=a[cnt++];
		for(int j=m-2-i;j>=i+1&&cnt<N-1;j--) b[j][i] = a[cnt++];
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout << b[i][j];
			if(j!=n-1) cout << " ";
		}
		cout << '\n';
	}
	return 0;
}
