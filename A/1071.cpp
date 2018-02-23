#include <iostream>
#include <map>
#include <string>
#include <cctype>
using namespace std;

int main(){
	string s,w;
	map<string,int> m;
	getline(cin,s);
	for(int i=0;i<s.length();i++){
		if(isalnum(s[i])){   //判断字符是否为大小写字母或‘0’~‘9’字符 
			s[i]=tolower(s[i]);  
			w+=s[i];
		}else{
			if(w.length()){
				m[w]++;
			}
			w="";//重置，准备判断下一个单词 
		}
	}
	if(w.length()){   //必须再判断一次，否则可能少一个合法单词 
		m[w]++;
	}
	int MAX=0;
	for(auto it=m.begin();it!=m.end();it++){
		if(it->second>MAX){
			MAX=it->second;
			w=it->first;
		}
	}
	cout << w << " " << MAX << endl;
	return 0;
}
