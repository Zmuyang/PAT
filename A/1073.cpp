#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	cin >> s;
	if(s[0]=='-') cout << s[0];
	s.erase(0,1);
	int point = s.find(".");
	int E=s.find("E");
	int M(0);
	char mark=s[E+1];
	for(int i=E+2;i<s.length();i++){
		M=s[i]-'0'+M*10;
	}
	s.erase(point,1);
	s.erase(E-1,s.length()-E+1);
	if(mark=='-'){
		for(int i=0;i<M;i++){
			s.insert(0,"0");
		}
		s.insert(1,".");
	}else{
		int cnt=E-point-1;
		if(cnt==M){
			cout << s;
			return 0;
		}else if(cnt<M){
			for(int i=0;i<M-cnt;i++){
				s.append("0");  //追加 
			}
		}else if(cnt>M){
			if(s[0]=='0'){
				s.erase(0,1);
				s.insert(M,".");
			}else{
				s.insert(M+1,".");//指定位置插入 
			}
		}
	}
	
	cout <<s;
	return 0;
}
