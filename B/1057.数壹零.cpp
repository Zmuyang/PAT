#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int main(){
	string s;
	getline(cin,s);
	int n(0),a[2]={0};
	for(int i=0;i<s.length();i++){
		if(isalpha(s[i])){
			s[i]=toupper(s[i]);
			n+=(s[i]-'A'+1);
		}
	}
	while(n){
		a[n%2]++;
		n/=2;
	}
	cout << a[0] << " " << a[1] << endl;
	return 0;
}
