#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int n,flag=0;
	char a[11]={'1','0','X','9','8','7','6','5','4','3','2'};
	int weight[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	cin >> n;
	for(int i=0;i<n;i++){
		int sum(0);
		string s;
		cin >> s;
		for(int j=0;j<17;j++){
			
			sum+= (s[j]-'0')*weight[j];
		}
		if(a[sum%11]!=s[17]){
			cout << s << endl;
			flag = 1;
		}
	}
	if(flag==0) cout << "All passed" << endl;
	return 0;
}
