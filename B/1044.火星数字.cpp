#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

string Uit[13]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string Tit[13]={"tret","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};

string ns[170];
map<string,int> sn;
void init(){
	for(int i=0;i<13;i++){
		ns[i]=Uit[i];
		sn[Uit[i]]=i;
		ns[i*13]=Tit[i];
		sn[Tit[i]]=i*13;
	}
	for(int i=1;i<13;i++){
		for(int j=1;j<13;j++){
			string s = Tit[i]+" "+Uit[j];
			ns[i*13+j]=s;
			sn[s]=i*13+j;
		}
	}
}
int main(){
	init();
	int T;
	cin >> T;
	getchar();
	while(T--){
		string s;
		getline(cin,s);
		if(s[0]>='0'&&s[0]<='9'){
			int num(0);
			for(int i=0;i<s.length();i++) num=num*10+(s[i]-'0');
			cout << ns[num] << endl;
		}else{
			cout << sn[s]<< endl;
		}
		
	}
	return 0;
}
