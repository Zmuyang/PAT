#include <iostream>
using namespace std;

int main(){
	int n;
	double v,sum(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> v;
		sum+=v*i*(n+1-i);
	}
	printf("%.2f\n",sum);
	return 0;
} 
