#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;

int main(){
	string num;
	int flag(0);
	int book[10]={0};
	cin >> num;
	int len = num.size();
	for(int i=len-1;i>=0;i--){
		int temp = num[i]-'0';
		book[temp]++;
		temp = temp*2+flag;
		flag=0;
		if(temp>=10){
			temp-=10;
			flag=1;
		}
		num[i]=(temp+'0');
		book[temp]--;
	}
	int mark=0;
	for(int i=0;i<10;i++){
		if(book[i]!=0){
			mark=1;
		}
	}
	if(flag==1||mark==1){
		printf("No\n");
	}else{
		printf("Yes\n");
	}
	if(flag==1){
		printf("1");
	}
	for(int i=0;i<len;i++){
		printf("%c",num[i]);
	}
	return 0;
} 
