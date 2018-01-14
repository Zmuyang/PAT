#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int main(){
	string s;
	getline(cin,s);
	int a[26]={0},max(0),t(0);
	for(int i=0;i<s.length();i++){
		s[i] = tolower(s[i]);   // Ð¡Ð´×ª»» 
	}
	for(int i=0;i<s.length();i++){
		if(s[i]>='a' && s[i]<='z'){
			a[s[i]-'a']++;
		}
	}
	max=a[0];
	for(int i=1;i<26;i++){
		if(a[i]>max){
			max= a[i];
			t= i;
		}
	}
	char temp = t+'a';
	cout << temp << " " << max;
	return 0;
}
