#include <iostream>
#include <string>

using namespace std;

struct St{
	string Name;
	string ID;
	int Grade;
}S[1000],M[2];

int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> S[i].Name >> S[i].ID >> S[i].Grade;
	}
	M[0]=S[0];
	M[1]=S[0];
	for(int i=1;i<n;i++){
		if(S[i].Grade>M[0].Grade){
			M[0]=S[i];
		}
		if(S[i].Grade<M[1].Grade){
			M[1]=S[i];
		}
	}
	cout << M[0].Name <<" "<< M[0].ID << endl;
	cout << M[1].Name <<" "<< M[1].ID << endl;
	return 0;
}
