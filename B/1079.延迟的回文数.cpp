#include <iostream>
#include <algorithm>
using namespace std;

string Add(string s);

int main(){
	string s;
	cin >> s;
	int cnt(0);
	while(cnt<10){
		string temp=s;
		reverse(temp.begin(),temp.end());
		if(temp==s){
			cout << s << " is a palindromic number.";
			break;
		}else{
			cout << s << " + " << temp << " = " << Add(s) << endl;
			s=Add(s);
			cnt++;
		}
	}
	if(cnt==10){
		cout << "Not found in 10 iterations.";
	}
	return 0;
}
string Add(string s){
	string S = s;
	string temp;
	reverse(S.begin(),S.end());
	int carry(0);
	for(int i=0;i<s.length();i++){
		int num = (S[i]-'0'+s[i]-'0')+carry;
		carry=0;
		if(num>=10){
			carry=1;
			num-=10;
		}
		temp+=char(num+'0');
	}
	if(carry==1){
		temp+='1';
	}
	reverse(temp.begin(),temp.end());
	return temp;
}
