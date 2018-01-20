#include <iostream>
#include <string>
using namespace std;

int main(){
	string r,t;
	int n,cnt(0);
	cin >> r >> n;
	getchar();  //³Ôµô»Ø³µ 
	while(1){
		getline(cin,t);
		if(t=="#") break;
		cnt++;
		if(cnt<=n&&t==r){
			cout << "Welcome in";
			break;
		}else if(cnt<=n && t!=r){
			cout << "Wrong password: " << t << endl;
			if(cnt==n){
				cout << "Account locked";
				break;
			}
		}
	}
	return 0;
}
