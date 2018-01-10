#include <iostream>
#include <vector>
using namespace std;

int main(){
	int A,B,D,sum(0),cnt(0);
	cin >> A >> B >> D;
	sum = A+B;
	if(sum==0){
		cout << sum;
		return 0;
	}
	while(sum){
		cnt++;
		sum/=D;
	}
	sum=A+B;
	vector<int> N(cnt);
	for(int i=0;i<cnt;i++){
		N[i]=sum%D;
		sum/=D;
	}
	for(int i=cnt-1;i>=0;i--){
		cout << N[i];
	}
	return 0;
}
