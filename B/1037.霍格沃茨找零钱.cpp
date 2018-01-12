#include <iostream>

using namespace std;

int main(){
	long long int margin(0);
	int PG,PS,PK;
	int AG,AS,AK;
	scanf("%d.%d.%d",&PG,&PS,&PK);
	scanf("%d.%d.%d",&AG,&AS,&AK);
	long long int Psum = PG*17*29 + PS*29 +PK;	
	long long int Asum = AG*17*29 + AS*29 +AK;
	if(Psum<=Asum){
		margin = Asum-Psum;
	}else{
		cout <<'-';
		margin = Psum-Asum;
	}
	if(margin==0){
		cout << 0<<'.'<<0<< '.'<<0;
		return 0;
	}	
	cout << margin/(17*29) << '.'<< margin%(17*29)/29 << '.' << margin%29;
	return 0;
}
