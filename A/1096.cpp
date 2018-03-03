#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	long long n,len(0),I(0);
	cin >> n;
	long long sqr=(long long)sqrt(1.0*n);
	for(int i=2;i<=sqr;i++){
		long long temp(1),j=i;
		while(1){
			temp*=j;
			if(n%temp!=0) break;
			if(j-i+1>len){
				I=i;
				len=j-i+1;
			}
			j++;
		}
	}
	if(len==0){
		cout << 1 << '\n' << n << endl;
	}else{
		cout << len << '\n';
		for(long long i=0;i<len;i++){
			cout << I+i;
			if(i<len-1) cout << '*';
		}
	}
	return 0;
} 
