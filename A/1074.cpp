#include <iostream>
using namespace std;

int main(){
	int F,k,n,sum(0);
	int temp,data[100005],next[100005],list[100005],result[100005];
	cin >> F >> n >> k;
	for(int i=0;i<n;i++){
		cin >> temp;
		cin >> data[temp] >> next[temp];
	}
	while(F!=-1){
		list[sum++]=F;
		F=next[F];
	}
	for(int i=0;i<sum;i++) result[i]=list[i];
	for(int i=0;i<(sum-sum%k);i++){
		result[i]=list[i/k*k+k-1-i%k];
	}
	for(int i=0;i<sum-1;i++){
		printf("%05d %d %05d\n",result[i],data[result[i]],result[i+1]);
	}
	printf("%05d %d -1\n",result[sum-1],data[result[sum-1]]);
	return 0;
}
