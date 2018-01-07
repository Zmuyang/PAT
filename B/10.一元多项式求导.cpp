#include <iostream>
using namespace std;

int main(){
	int a,b;
	int flag = 0;  // flag用来判断是否是第一次输出 
	while(cin >> a >> b){
		if(b==0){
			if(flag==0){
				cout << "0 0";  //因为是指数递降，若第一次指数就是0，直接输出 0 0 
			}
			return 0;
		}
		if(flag==1){    // 若不是第一次输出 
			cout << " ";
		}
		cout << a*b << " " << b-1;
		flag=1;
	}
	if(flag==0){  //若没有输入 
		cout << "0 0";
	}
	return 0; 
}
