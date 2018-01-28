#include <iostream>
#include <string>
using namespace std;

int main(){
	long long int a,b,c;
	cin >> a >> b;
	c=a+b;
	if(c<0){
		cout <<'-';
		c=-c;
	}
	string s = to_string(c);
	long long int len = s.length();
	for(int i=0;i<len;i++){
		if(i%3==len%3&&i!=len-1&&i!=0){
			cout << ',';
		}
		cout << s[i];
	}
	return 0;
} 
