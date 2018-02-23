#include <iostream>
#include <algorithm>
using namespace std;

struct Mooncakes{
	float inventory, price,unit;
}N[1001];

int cmp(Mooncakes a,Mooncakes b){
	return a.unit>b.unit;
}

int main(){
	float sum(0.0),needs;
	int n;
	cin >> n >> needs;
	for(int i=0;i<n;i++){
		cin >> N[i].inventory;
	}
	for(int i=0;i<n;i++){
		cin >> N[i].price;
		N[i].unit=N[i].price/N[i].inventory;
	}
	sort(N,N+n,cmp);
	for(int i=0;i<n;i++){
		if(needs>=N[i].inventory){
			sum+=N[i].price;
			
		}else{
			sum+=(needs*N[i].unit);
			break;
		}
		needs-=N[i].inventory;
	}
	printf("%.2f\n",sum);
	return 0;
}
