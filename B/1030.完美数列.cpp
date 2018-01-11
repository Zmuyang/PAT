#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int n,result(1);
	long long int p;
	cin >> n >> p;
	if(n==0){
		cout << n;
		return 0;
	}
	vector<long long int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	
	sort(a.begin(),a.end());
	
	for(int i=0;i<n-1;i++){
		for(int j=i+result;j<n;j++){
			if(a[j]>a[i]*p) break;
			result = max(result,j-i+1);
		}
	}
	cout << result << endl;
	return 0;
}
