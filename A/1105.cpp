#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn(10010);
int matrix[maxn][maxn],A[maxn];

bool cmp(int a ,int b){
	return a>b;
}

int main(){
	int N;
	cin >> N;
	for(int i=0;i<N;i++) cin >>  A[i];
	if(N==1){
		cout << A[0];
		return 0;
	}
	
	sort(A,A+N,cmp);
	int m=(int)ceil(sqrt(1.0*N));
	while(N%m!=0) m++;
	int n=N/m,i(1),j(1),now(0);
	int u(1),D=m,L=1,R=n; //上下左右边界
	while(now<N){
		while(now<N&&j<R){ //向右填充 
			matrix[i][j]=A[now++];
			j++;
		}
		while(now<N&&i<D){
			matrix[i][j]=A[now++];
			i++;
		}
		while(now<N&&j>L){
			matrix[i][j]=A[now++];
			j--;
		}
		while(now<N&&i>u){
			matrix[i][j]=A[now++];
			i--;
		}
		u++,D--,L++,R--; //缩小边界
		i++,j++;
		if(now==N-1){
			matrix[i][j]=A[now++];
		} 
	} 
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cout << matrix[i][j];
			if(j<n){
				cout << " ";
			}else cout << '\n';
		}
	}
	return 0;
} 
