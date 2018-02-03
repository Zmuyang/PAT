#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

bool Prime(int n);
int main(){
	int N,D;
	while(scanf("%d",&N)!=EOF){
		if(N<0){
			break;
		}
		scanf("%d",&D);
		if(Prime(N)==false){
			cout << "No" << endl;
			continue;
		}
		int cnt(0);
		int arr[100];
		do{
			arr[cnt++] = N % D;
			N= N / D;
		}while(N!=0);
		for(int i=0;i<cnt;i++){
			N=N*D+arr[i];
		}
		if(Prime(N)==false){
			cout << "No" << endl;
		}else{
			cout << "Yes" << endl;
		}
	} 
	return 0;
}
bool Prime(int n){
	if(n<=1) {
		return false;
	}
	for(int i=2;i<=int(sqrt(n*1.0));i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}
  
