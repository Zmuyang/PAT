#include <iostream> 
#include <vector>
using namespace std;

int main(){
	int N,sum(0);
	cin >> N;
	vector<int> a(N);
	for(int i=0;i<N;i++){
		cin >> a[i];
		sum+=a[i]*10*(N-1);
		sum+=a[i]*(N-1);
	}
	cout << sum << endl;
	return 0;
} 
