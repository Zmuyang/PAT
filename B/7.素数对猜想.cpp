#include <iostream>
#include <cmath>
using namespace std;

bool PrimeNumber(int a);

int main(){
	int n;
	int arr[100000];
	int j(0); 
	cin >> n;
	for(int i=1;i<=n;i++){
		if(PrimeNumber(i)){
			arr[j++]=i;
		}
	}
	int cnt(0);
	for(int i=1;i<j;i++){
		if(arr[i]-arr[i-1]==2){
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}

bool PrimeNumber(int a){
	for(int i=2;i<=sqrt(a);i++){   //判断素数高效算法 
		if(a%i==0){
			return false;
		}
	}
	return true;
} 
