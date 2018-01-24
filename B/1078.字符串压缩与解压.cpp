#include <iostream>
using namespace std;
int main(){
	char c;
	string s;
	scanf("%c",&c);
	getchar();
	getline(cin,s);
	if(c=='C'){
		char pre=s[0];
		int cnt(1);
		for(int i=1;i<=s.size();i++){
			if(s[i]==pre){
				cnt++;
				continue;
			}
			if(cnt>=2){
				cout << cnt << pre;
				pre=s[i];
				cnt=1;
				continue;
			}else{
				cout << pre;
				pre=s[i];
				cnt=1;
			}
		}
	}
	
	if(c=='D'){
		string num;
		char pre;
		int cnt(1);
		for(int i=0;i<=s.size();i++){
			if(s[i]>='0'&&s[i]<='9'){
				num+=s[i];
			}else{
				if(num.length()>0) cnt=stoi(num);
				while(cnt--){
					cout << s[i];
				}
				cnt=1;
				num="";
			}
		}
	}
	return 0;
}
