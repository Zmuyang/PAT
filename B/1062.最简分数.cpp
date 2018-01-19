#include <iostream>
#include <cstdio>
using namespace std;

int Fun(int a,int b) {
	return b==0 ? a : Fun(b,a%b) ;
}

int main(){
	int a,b,c,d,e;
	scanf("%d/%d %d/%d %d",&a,&b,&c,&d,&e);
	if(a*d > c*b){
		swap(a,c);
		swap(b,d);
	}
	int num(1);
	bool flag(false);
	while(a*e>=b*num) num++;
	while(a*e<b*num && d*num<c*e){
		if(Fun(num,e)==1){
			printf("%s%d/%d",flag==true ? " ":"",num,e);
			flag=true;
		}
		num++;
	}
	return 0;
} 
