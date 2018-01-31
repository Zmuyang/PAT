#include <iostream> 
#include <vector> 
using namespace std;

int main(){
	int N,temp,sum(0);
	cin >> N;
	vector<int> F(N);
	for(int i=0;i<N;i++){
		if(i!=0){
			cin >> F[i];
			int t=F[i]-F[i-1];
			if(t<0){
				t=-t;
				sum+=t*4;
			}else{
				sum+=t*6;
			}
		}else{
			cin >> F[i];
		}
	}
	sum+=N*5;
	sum+=(F[0]-0) * 6;
	cout << sum << endl;
	return 0;
}
