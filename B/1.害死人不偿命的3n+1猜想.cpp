#include <iostream>
using std::cout; 
using std::cin;
using std::endl;

int main(void){
	int n=0,step=0;
	cin >> n;
	if(n==1) {
		cout << step << endl ;
		return 0;
	}
	while(n!=1){
		if(n%2==0){
			n=n/2;
			step++;
		}else{
			n=(3*n+1)/2;
			step++;
		}
	}
	cout << step << endl;
	return 0;
}
