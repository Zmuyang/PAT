#include <iostream> 
#include <stack>  
using namespace std;

int main(){
	stack<string> s;   // Õ» 
	string a;
	while(cin >> a){   // cin Óö¿Õ¸ñÍ£Ö¹ 
		s.push(a);
	}
	cout << s.top();
	s.pop();
	while(!s.empty()){
		cout << " " << s.top();
		s.pop();
	}
	return 0;
} 
