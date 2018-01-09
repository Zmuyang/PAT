#include <iostream>

using namespace std;

int main(){
	int sum1(0),sum2(0);
	long long int fir , f , two ,t;
	cin >> fir >> f >> two >> t;
	fir*=10;
	two*=10;
	while(fir/=10){
		if(fir%10==f){
			sum1*=10;
			sum1+=f;
		}
	}
	
	while(two/=10){
		if(two%10==t){
			sum2*=10;
			sum2+=t;
		}
	}
	cout << sum1+sum2 << endl;
	return 0;
}
