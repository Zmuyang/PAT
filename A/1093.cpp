// code1
#include <iostream>
#include <string>
using namespace std;

int Lp[100010];

int main(){
	string s;
	cin >> s;
	for(int i=0;i<s.length();i++){
		if(i>0){
			Lp[i]=Lp[i-1];
		}
		if(s[i]=='P'){
			Lp[i]++;
		}
	}
	int ans(0),T(0);
	for(int i=s.length()-1;i>=0;i--){
		if(s[i]=='T'){
			T++;
		}
		if(s[i]=='A'){
			ans+=(Lp[i]*T);
			ans%=1000000007;
		}
	}
	cout << ans << endl;
	return 0;
}



//code2
#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	cin >> s;
	int len=s.length();
	int ans(0),P(0),T(0);
	for(int i=0;i<len;i++){
		if(s[i]=='T') T++;
	}
	
	for(int i=0;i<len;i++){
		if(s[i]=='P') P++;
		if(s[i]=='T') T--;
		if(s[i]=='A') ans=(ans+P*T)%1000000007;
	}
	cout << ans;
	return 0;
}
