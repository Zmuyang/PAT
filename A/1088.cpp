#include <iostream>
#include <algorithm> 

using namespace std;

long long gcd(long long a,long long b){   //求a与b的最大公约数 
	return b==0?a:gcd(b,a%b);
}

struct Fraction{
	long long up,down; //分子，分母 
}a,b; 

Fraction reduction(Fraction result){ 		//化简 
	if(result.down<0){  
		result.up=-result.up;
		result.down=-result.down;
	}
	if(result.up==0){
		result.down=1; 
	}else{
		int d=gcd(abs(result.up),abs(result.down));
		result.up/=d;
		result.down/=d;
	}
	return result;
}

Fraction add(Fraction f1,Fraction f2){  //加法 
	Fraction result;
	result.up=f1.up*f2.down+f1.down*f2.up;
	result.down=f1.down*f2.down;
	return reduction(result);
}

Fraction minu(Fraction f1,Fraction f2){  //减法 
	Fraction result;
	result.up=f1.up*f2.down-f1.down*f2.up;
	result.down=f1.down*f2.down;
	return reduction(result);
}

Fraction multi(Fraction f1,Fraction f2){
	Fraction result;
	result.up=f1.up*f2.up;
	result.down=f1.down*f2.down;
	return reduction(result);
}

Fraction divide(Fraction f1,Fraction f2){
	Fraction result;
	result.up=f1.up*f2.down;
	result.down=f1.down*f2.up;
	return reduction(result);
}

void showResult(Fraction x){
	x=reduction(x);
	if(x.up<0) cout << '(';
	if(x.down==1) cout <<x.up;
	else if(abs(x.up)/x.down){
		printf("%lld %lld/%lld",x.up/x.down,abs(x.up)%x.down,x.down);
	}else {  //真分数 
		printf("%lld/%lld",x.up,x.down);
	}
	if(x.up<0) cout << ')';
}

int main(){
	scanf("%lld/%lld %lld/%lld",&a.up,&a.down,&b.up,&b.down);
	showResult(a);
	cout << " + ";
	showResult(b);
	cout << " = ";
	showResult(add(a,b));
	cout << '\n';
	
	showResult(a);
	cout << " - ";
	showResult(b);
	cout << " = ";
	showResult(minu(a,b));
	cout << '\n';
	
	showResult(a);
	cout << " * ";
	showResult(b);
	cout << " = ";
	showResult(multi(a,b));
	cout << '\n';
	
	showResult(a);
	cout << " / ";
	showResult(b);
	cout << " = ";
	if(b.up==0) cout << "Inf" << endl;
	else showResult(divide(a,b));
	return 0;
}
