#include <iostream>
#include <vector>

using namespace std;

int main(){
	int N,sum(0),left,right;
	cin >> N;
	vector<int> Len(N+1);

	for(int i=1;i<=N;i++){
		int x;
		cin >> x;
		sum+=x;
		Len[i]=sum;
	}
	
	int M;
	cin >> M;
	for(int i=0;i<M;i++){
		cin >> left >> right;
		if(left>right){
			swap(left,right);
		}
		int dis=Len[right-1]-Len[left-1];
		cout << min(dis,sum-dis) << endl;
	}
	return 0;
} 
