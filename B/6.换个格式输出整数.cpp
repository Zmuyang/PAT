#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	for(int i=0;i<n/100;i++){
		cout << 'B';
	}
	for(int i=0;i<n%100/10;i++){
		cout << 'S';
	}
	for(int i=1;i<=n%10;i++){
		cout << i;
	}
	return 0;
} 
