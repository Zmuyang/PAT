#include <iostream>
#include <cmath>
using namespace std;

bool PrimeN(int a);

int main(){
	int mark = 0;
	int a[10000];
	int m,n;
	cin >> m >> n;
	int j=1;
	for(int i=2;i<200000;i++){
		if(j==n+1) break;
		if(PrimeN(i)){
			a[j++]=i;
		}
	}
	if(m==n){
		cout << a[m];
		return 0;
	}
	int step=1;
	for(int i=m;i<j-1;i++){
		cout << a[i];
		if(step<10){
			cout << " ";
			step++;
		}else{
			cout << "\n";
			step=1;
		}
	}
	cout << a[j-1];
	return 0;
}

bool PrimeN(int a){
	for(int i=2;i<=sqrt(a);i++){
		if(a%i==0){
			return false;
		}
	}
	return true;
}
