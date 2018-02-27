#include <iostream>
#include <cstdio>
using namespace std;

long long int Func(long long int a,long long int b){
	return b==0?abs(a):Func(b,a%b);
}

int main(){
	long long int n,x(0),y(1),temp;
	cin >> n;
	for(int i=0;i<n;i++){
		long long int X,Y;
		scanf("%lld/%lld",&X,&Y);
		temp=Func(X,Y);
		X/=temp;
		Y/=temp;
		x=x*Y+y*X;
		y=y*Y;
		temp=Func(x,y);
		x/=temp;
		y/=temp;
	}
	temp=x/y;
	x=x-(y*temp);
	if(temp!=0){
		cout << temp;
		if(x!=0) cout << " ";
	}
	if(x!=0){
		cout << x << '/' << y << endl;
	}
	if(temp==0&&x==0){
		cout << 0 << endl;
	}
	return 0;
}
