#include <iostream>
#include <cctype>

using namespace std;

int main(){
	string a,b;
	int cnt(0);
	char s[80];
	cin >> a >> b;
	for(int i=0;i<a.length();i++){
		int flag(0);
		for(int j=0;j<b.length();j++){
			if(a[i]==b[j]){
				flag=1;
				break;
			}
		}
		if(!flag) {
			s[cnt++] = toupper(a[i]);
		}
	}
	for(int i=1;i<cnt;i++){
		for(int j=0;j<i;j++){
			if(s[i]==s[j]){
				s[i]='*';
				break;
			}
		}
	}
	for(int i=0;i<cnt;i++){
		if(s[i]!='*'){
			cout << s[i];
		}
	}
	return 0;
}
