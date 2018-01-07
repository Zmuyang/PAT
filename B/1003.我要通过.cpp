#include <iostream>
#include <string>

using namespace std;

void IsPat(string str);

int main(void){
	int n(0);
	cin >> n;
	for(int i=0;i<n;i++){
		string temp;
		cin >> temp;
		IsPat(temp);
	}
	return 0;
}

void IsPat(string str){
	int local_P(0),local_T(0);
	int countP(0),countT(0);
	bool status=true;
	for(int i=0;i<str.length();i++){
		if(str[i]!='P' && str[i]!='A' && str[i]!='T'){
			status = false;
		}
		if(str[i]=='P'){
			 local_P=i;
			 countP++;
		}
		if(str[i]=='T'){
			local_T=i;
			countT++;
			break;
		}
	}
	if((local_T-1-local_P)>=1 && local_P*(local_T-1-local_P)==(str.length()-1-local_T) && countP==1 && countT==1 && status){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
}


