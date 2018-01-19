#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
	int N,M;
	cin >> N >> M;
	vector<int> score(M),cnt(M);
	for(int i=0;i<M;i++) scanf("%d",&score[i]);
	for(int i=0;i<M;i++) scanf("%d",&cnt[i]);
	for(int i=0;i<N;i++){
		int sum(0);
		for(int j=0;j<M;j++){
			int temp(0);
			scanf("%d",&temp);
			if(temp==cnt[j]) sum+=score[j];
		}
		cout << sum << endl;
	}
	return 0;
} 
