#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	getchar();
	string ans;
	for(int i=0;i<n;i++){
		string s;
		getline(cin,s);
		reverse(s.begin(),s.end());
		if(i==0){
			ans=s;
			continue;
		}else{
			int len=min(ans.length(),s.length());
			for(int j=0;j<len;j++){
				if(ans[j]!=s[j]){
					ans.erase(j);
					break;
				}
			}
		}
	}
	
	if(ans.length()==0){
		cout << "nai" << endl;
	}else{
		reverse(ans.begin(),ans.end());
		cout << ans << endl;
	}
	return 0;
} 
