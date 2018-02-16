#include <iostream>
using namespace std;

const int N(54);
char mp[5]={'S','H','C','D','J'};
int start[N+1],End[N+1],Next[N+1];

int main(){
	int K;
	cin >> K;
	for(int i=1;i<=N;i++){
		start[i]=i;
	}
	for(int i=1;i<=N;i++){
		cin >> Next[i];
	}
	for(int cnt=0;cnt<K;cnt++){
		for(int i=1;i<=N;i++){
			End[Next[i]]=start[i];
		}
		for(int i=1;i<=N;i++){
			start[i]=End[i];
		}
	}
	for(int i=1;i<=N;i++){
		if(i!=1) cout << " ";
		start[i]--;
		cout << mp[start[i]/13] << start[i]%13+1;
	}
	return 0;
}
