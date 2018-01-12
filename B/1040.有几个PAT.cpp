#include <iostream>
#include <string>

using namespace std;

int main(){
	string s;
	cin >> s;
	int result(0),cntp(0),cntt(0);
	for(int i=0;i<s.length();i++){
		if(s[i]=='T') cntt++;
	}
	
	for(int i=0;i<s.length();i++){
		if(s[i]=='P') cntp++;
		if(s[i]=='T') cntt--;
		if(s[i]=='A'){
			result += (cntp*cntt%1000000007);
			result %= 1000000007;
		}
	}
	cout << result;
	return 0;
}
