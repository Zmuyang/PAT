#include <iostream>
using namespace std;

int main(){
	string s;
	cin >> s;
	int N=s.size();
	int L = (N+2)/3;
	int bottom = N-2*L+2;
	for(int i=0;i<L-1;i++){
		cout << s[i];
		for(int ix=0;ix<bottom-2;ix++){
			cout << " ";
		}
		cout << s[N-1-i] << endl;
	}
	for(int i=L-1;i<N-L+1;i++){
		cout << s[i];
	}
	return 0;
}
