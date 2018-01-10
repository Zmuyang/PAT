#include <iostream>
#include <string>

using namespace std;

int main(){
	int E(0),Mi(0),sum(0),cnt(0);
	string s;
	cin >> s;
	
	if(s[0]=='-'){
		cout << '-';
	}
	
	for(int i=0;i<s.length();i++){
		if(s[i]=='E'){
			E=i;
			break;
		}
	}
	for(int i=1;i<s.length();i++){
		if(s[i]!='.'){
			cnt++;
		}else {
			break;
		}
	}
	for(int i=E+2;i<s.length();i++){
		sum*=10;
		sum+=(s[i]-'0');
	}
	if(s[E+1]=='-'){
		if(sum>0){
			cout << "0.";
			for(int i=1;i<sum;i++){
				cout << '0';
			}
			for(int i=1;i<E;i++){
				if(s[i]>='0'&&s[i]<='9') cout << s[i];
			}
		}else{
			for(int i=1;i<E;i++){
				cout << s[i];
			}
		}
	}else{
		if(E-3<sum){
			if(s[1]!=0) cout << s[1];
			for(int i=3;i<E;i++){
				if(s[i]>='0'&&s[i]<='9') cout << s[i];
			}
			for(int i=0;i<sum-(E-3);i++) cout << '0';
		}else{
			if(s[1]!='0') cout << s[1];
			for(int i =3;i<E;i++){
				if(sum+3==i) cout << '.';
				if(s[i]>='0'&&s[i]<='9') cout << s[i];
			}
		}
		
	}
	return 0;
} 
