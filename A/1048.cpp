#include <iostream>
#include <vector>
using namespace std;
int coin[100005]={0};

int main(){
	int N,M;
	cin >> N >> M;
	for(int i=0;i<N;i++){
		int index;
		cin >> index;
		coin[index]++;
	}
	for(int i=0;i<1001;i++){
		if(coin[i]!=0){
			coin[i]--;
			if(coin[M-i]!=0){
				cout << i << " " << M-i << endl;
				return 0;
			}
		}
	}
	cout << "No Solution" << endl;
	return 0;
}
