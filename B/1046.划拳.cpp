#include <iostream>
using namespace std;

int main(){
	int N,cnt1(0),cnt2(0);
	cin >> N;
	for(int i=0;i<N;i++){
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		if( (b==d&&b==a+c) || (b!=a+c&&d!=a+c)){
			continue;
		}
		if(b==a+c){
			cnt2++;
		}
		if(d==a+c){
			cnt1++;
		}
	}
	cout << cnt1 << " " << cnt2 << endl;
} 
