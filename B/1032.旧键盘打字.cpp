#include <iostream>
#include <cctype>

using namespace std;

int main(){
	string bad,F;
	int flag(0),cnt(0);
	getline(cin,bad);
	getline(cin,F);
	if(bad.length()==0){
		cout << F;
		return 0;
	}
	for(int i=0;i<bad.length();i++) {
		if(bad[i]=='+') {
			flag=1;
			break;
		}
	} 
	for(int i=0;i<F.length();i++){
		for(int j=0;j<bad.length();j++){
			if((bad[j]==F[i]||(bad[j]==toupper(F[i]))||(flag==1&&F[i]>='A'&&F[i]<='Z'))){
				F[i]='*';
				cnt++;
			}
		}
	}
	

	for(int i=0;i<F.length();i++){
		if(F[i]!='*') {
			cout << F[i];
			cnt=1;
		}
	}
	if(cnt==0) cout << endl;
	return 0;
} 
