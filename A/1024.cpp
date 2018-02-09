#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

string s;

void add(){
	string t=s;
	reverse(t.begin(),t.end());
	int len = s.size();
	int flag(0);
	for(int i=0;i<len;i++){
		s[i] = s[i]+t[i]+flag - '0';
		flag=0;
		if(s[i]>'9'){
			s[i]-=10;
			flag=1;
		}
	}
	if(flag) s+='1';
	reverse(s.begin(),s.end());   //题意是先反转然后再加上原来的数字，所以这里需要反转回来 
}

int main(){
	int cnt(0);
	cin >> s >> cnt;
	for(int i=0;i<=cnt;i++){
		string t=s;
		reverse(t.begin(),t.end());
		if(s==t){
			cout << s << '\n' << i<< endl;
			return 0;
		}
		if(i!=cnt){
			add();
		}
	}
	cout << s << '\n' << cnt << endl;
	return 0;
}
