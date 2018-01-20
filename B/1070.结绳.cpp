#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int N,sum(0);
	cin >> N;
	vector<int> a(N);
	for(int i=0;i<N;i++){
		cin >>a[i]; 
	}
	sort(a.begin(),a.end());
	sum = a[0];
	for(int i=1;i<N;i++) {
		sum = (sum+a[i])/2;
	} 
	printf("%d",sum);
	return 0;
}
