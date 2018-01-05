#include <iostream>
#include <string>
using namespace std;

int main(void){
	string str[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	string num("");
	int sum(0);
	cin >> num;
	for(int i=0;i<num.length();i++){
		sum+=num[i]-'0';
	}
	string s1= to_string(sum);  // C++11新特性 ， 将int转换为string 
	
	for(int i=0;i<s1.length();i++){
		if(i!=s1.length()-1){
			cout << str[s1[i]-'0'] << " ";
		}else{
			cout << str[s1[i]-'0'];
		}
	}
	return 0;
}
