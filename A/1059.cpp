#include <cstdio>
#include <vector>
using namespace std;
vector<int> prime(500000,1);
int main(){
	for(int i=2;i*i<500000;i++){
		for(int j=2;j*i<500000;j++){
			prime[j*i]=0;
		}
	}
	long int x;
	scanf("%ld",&x);
	printf("%ld=",x);
	if(x==1) printf("1");
	bool state=false;  //务必初始化 
	for(int i=2;x>=2;i++){
		int flag=0,cnt=0;
		while(prime[i]==1 && x%i==0){
			cnt++;
			x/=i;
			flag=1;
		}
		if(flag){
			if(state) printf("*");
			printf("%d",i);
			state=true;
		}
		if(cnt>1){
			printf("^%d",cnt);
		}
	}
	return 0;
}
