#include <iostream> 
#include <string>
using namespace std;

int main(){
	string s1,s2;
	cin >> s1 >> s2;
	int cnt(0);
	for(int i=0;i<s2.length();i++){
		int index=s1.find(s2[i]);
		if(index==string::npos){
			cnt++;
		}else{
			s1.erase(index,1);
		}
	}
	if(!cnt){
		cout << "Yes" << " " << s1.length();
	}else{
		cout << "No" << " " << cnt;
	}
	return 0;
}
