#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cmp(int a,int b){
	return a>b;
}

int main(){
	int N,M,sum(0),y(0),x(0);
	cin >> N ;
	vector<int> C(N);
	for(int i=0;i<N;i++){
		cin >> C[i];
	}
	cin >> M;
	vector<int> P(M);
	for(int i=0;i<M;i++){
		cin >> P[i];
	}
	sort(C.begin(),C.end(),cmp);
	sort(P.begin(),P.end(),cmp);
	for(;x<C.size()&&C[x]>0;x++);
	for(;y<P.size()&&P[y]>0;y++);
	for(int i=0;i<min(x,y);i++){
		sum+=(C[i]*P[i]);
	}

	sort(C.begin(),C.end());
	sort(P.begin(),P.end());
	for(x=0;x<C.size()&&C[x]<0;x++);
	for(y=0;y<P.size()&&P[y]<0;y++);
	for(int i=0;i<min(x,y);i++){
		sum+=(C[i]*P[i]);
	}
	cout << sum;
	return 0;
}
