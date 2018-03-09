#include <iostream>
#include <string>
#include <map>
using namespace std;

string G[13]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string S[13]={"tret","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};

string x[170];
map<string,int> y;

void init(){
	for(int i=0;i<13;i++){
		x[i]=G[i];
		y[G[i]]=i;
		x[i*13]=S[i];
		y[S[i]]=i*13;
	}
	
	for(int i=1;i<13;i++){
		for(int j=1;j<13;j++){
			string str = S[i] + " " + G[j];
			x[i*13+j]=str;
			y[str]=i*13+j;
		}
	}
}

int main(){
	init();
	int N;
	scanf("%d%*c",&N);  // ÀàËÆÓÚ cin >> N ; getchar() 
	while(N--){
		string str;
		getline(cin,str);
		if(str[0]>='0'&&str[0]<='9'){
			int num(0);
			for(int i=0;i<str.length();i++){
				num=num*10+(str[i]-'0');
			}
			cout << x[num] << endl;
		}else cout << y[str] << endl;
	}
	return 0;
}
