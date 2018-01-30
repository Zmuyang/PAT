#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int N,MIN(11100000),MAX(0);
	string U,L;
	cin >> N;
	for(int i=0;i<N;i++){
		string ID;
		cin >> ID;
		int h,m,s,H,M,S;
		scanf("%d:%d:%d %d:%d:%d",&h,&m,&s,&H,&M,&S);
		int unlocked = h*3600+m*60+s;
		int locked = H*3600+M*60+S;
		if(unlocked<MIN){
			MIN=unlocked;
			U=ID;
		}
		if(locked>MAX){
			MAX=locked;
			L=ID;
		}
	}
	cout << U << " " << L << endl;
	return 0;
} 
