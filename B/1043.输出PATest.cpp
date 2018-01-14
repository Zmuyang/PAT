#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(){
	char t;
	map<char,int> m;
	while(cin >> t){
		if(t=='P'||t=='A'||t=='T'||t=='e'||t=='s'||t=='t'){
			m[t]++;
		}
	}
	char c[7] = {"PATest"};
	int maxcnt(0);
	for(auto it:m){
		maxcnt=max(maxcnt,it.second);
	}
	for(int i=0;i<maxcnt;i++){
		for(int j=0;j<6;j++){
			if(m[c[j]]!=0){
				cout << c[j];
				m[c[j]]--;
			}
		} 
	}
	return 0;
}  
