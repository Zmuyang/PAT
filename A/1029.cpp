#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int N ,M;
	cin >> N;
	vector<int> v1(N);
	for(int i=0;i<N;i++){
		cin >> v1[i];
	}
	cin >> M;
	vector<int> v2(M);
	for(int i=0;i<M;i++){
		cin >> v2[i];
	}
	vector<int> v(N+M);
	merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v.begin());
	int cnt= (v.size()-1)/2;
	cout << v[cnt];
	return 0;
}
