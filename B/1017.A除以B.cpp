/*
	大整数除法，利用字符串高精度计算 
*/
#include <iostream>
#include <string>

using namespace std;

int main(){
	string s;
	cin >> s;
	int a;
	cin >> a;
	int len = s.length();
	int t = (s[0]-'0')/a;
	if((t!=0&&len>1) || len==1){
		cout << t;
	}
	int temp = (s[0]-'0') % a;
	for(int i=1;i<len;i++){
		t = (temp*10 + s[i]-'0')/a;
		cout << t;
		temp = (temp*10 + s[i]-'0')%a;
	}
	cout << " " << temp;
	return 0;
}
