#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int N,M;
	cin >> N >> M;
	for(int i=0;i<N;i++){
		int cnt(-2),Max(-1),Min=M+1,g1,g2(0),temp;
		cin >> g1;
		for(int j=0;j<N-1;j++){
			cin >> temp;
			if(temp>=0&&temp<=M){
				if(temp>Max) Max=temp;
				if(temp<Min) Min=temp;
				g2+=temp;
				cnt++;
			}
		}
		cout << int(((g2-Max-Min)*1.0/cnt+g1)/2+0.5) << endl;
	}
	return 0;
}
