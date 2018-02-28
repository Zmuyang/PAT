#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n,p,Max(1),a[100010];
	cin >> n >> p;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		//a[i+1] ~ a[n-1] 中查找第一个超过a[i]*p的数，并返回其位置 
		int j=upper_bound(a+i+1,a+n,(long long)a[i]*p)-a;//不减a的话会报错 
		Max=max(Max,j-i);
	}
	cout << Max<< endl;;
	return 0;
} 
