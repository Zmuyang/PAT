#include <iostream>
#include <cctype>
using namespace std;

int main(){
	string s1,s2,s3;
	cin >> s1 >> s2;
	for(int i=0;i<s1.length();i++){
		if(s2.find(s1[i])==string::npos && s3.find(toupper(s1[i]))==string::npos){   //string::npos 表示直到string末尾也未发现字符 
			s3+=toupper(s1[i]);
		}
	}
	cout << s3;
	return 0;
}
