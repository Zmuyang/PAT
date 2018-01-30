#include <iostream>
#include <string>
using namespace std;

int main(){
	string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
	int sum(0);
	string s;
	cin >> s;
	for(int i=0;i<s.size();i++){
		sum+=(s[i]-'0');
	}
	string S=to_string(sum);
	for(int i=0;i<S.size();i++){
		cout << arr[S[i]-'0'] ;
		if(i<S.size()-1) cout << " ";
	}
	return 0;
} 
