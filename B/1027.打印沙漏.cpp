#include <iostream>
#include <string>

using namespace std;

int main(){
	int N,row(0);
	char sign;
	cin >> N >> sign;
	
	for(int i=1;i<N;i++){
		if(2*i*(i+2)+1>N){   //求得不包括中间为1的行数 
			row = i-1;
			break;
		}
	}
	
	for(int i=row;i>=1;i--){
		for(int j=row-i;j>=1;j--){
			cout << ' ';
		}
		for(int k=2*i+1;k>=1;k--){
			cout << sign;
		}
		cout << endl;
	}
	
	for(int i=0;i<row;i++){
		cout << ' ';
	}
	 
	cout << sign << endl;
	
	for(int i=1;i<=row;i++){
		for(int j=row-i;j>=1;j--){
			cout << ' ';
		}
		for(int k=2*i+1;k>=1;k--){
			cout << sign;
		}
		cout << endl;
	}
	cout << (N-(2*row*(row+2)+1));
	return 0;
}
