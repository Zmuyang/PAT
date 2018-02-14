#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool CMP(string a,string b){
	return a+b<b+a;
}

int main(){
	int N;
	cin >> N;
	vector<string> str(N);
	for(int i=0;i<N;i++){
		cin >> str[i];
	}
	sort(str.begin(),str.end(),CMP);
	string s;
	for(int i=0;i<N;i++){
		s+=str[i];
	}
	while(s.length()!=0&&s[0]=='0'){
		s.erase(s.begin());
	}
	if(s.length()==0){
		cout << 0;
	}else{
		cout << s;
	}
	return 0;
}
