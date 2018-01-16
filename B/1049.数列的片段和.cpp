#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	double sum(0);
	cin >> n;
	vector<double> N(n);
	
	for(int i=0;i<n;i++){
		cin >> N[i];
		sum+= ((i+1)*N[i]*(n-i)); // 位置*数*包括数本身余下的数字个数 
	}
	printf("%0.2f",sum);
	return 0;
	
}
