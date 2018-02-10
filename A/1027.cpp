#include <iostream>
using namespace std;

int main(){
	char radix[14]={"0123456789ABC"};
	cout << '#';
	for(int i=0;i<3;i++){
		int num;
		cin >> num;
		printf("%c%c",radix[num/13],radix[num%13]);
	} 
	return 0;
}
