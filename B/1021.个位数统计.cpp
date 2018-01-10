#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	string s;
	vector<int> N(10,0);
	cin >> s;
	for(int i=0;i<s.length();i++){
		N[s[i]-'0']++;
	}
	for(int i=0;i<10;i++){
		if(N[i]!=0){
			cout << i << ":" << N[i] << endl;
		}
	}
	return 0;
} 
