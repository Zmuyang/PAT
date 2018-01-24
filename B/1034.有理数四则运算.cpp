#include <cstdio>
#include <algorithm>
using namespace std;

long long Gcd(long long a,long long b){     //求最大公约数 
	return b==0?a:Gcd(b,a%b);
}

struct Fraction{
	long long up,down;
}a,b;

Fraction reduction(Fraction result){
	if(result.down<0){
		result.up=-result.up;
		result.down=-result.down;
	}
	if(result.up==0){
		result.down=1;
	}else{
		int d= Gcd(abs(result.up),abs(result.down));
		result.up/=d;
		result.down/=d;
	}
	return result;
}

Fraction Add(Fraction f1,Fraction f2){
	Fraction result;
	result.up = f1.up*f2.down+f2.up*f1.down;
	result.down=f1.down*f2.down;
	return reduction(result);
}

Fraction Minu(Fraction f1,Fraction f2){
	Fraction result;
	result.up=f1.up*f2.down-f2.up*f1.down;
	result.down=f1.down*f2.down;
	return reduction(result);
}

Fraction Multi(Fraction f1,Fraction f2){
	Fraction result;
	result.up=f1.up*f2.up;
	result.down=f1.down*f2.down;
	return reduction(result);
}

Fraction Divide(Fraction f1,Fraction f2){
	Fraction result;
	result.up=f1.up*f2.down;
	result.down=f1.down*f2.up;
	return reduction(result);
}

void ShowResult(Fraction r){
	r=reduction(r);
	if(r.up<0) printf("(");
	if(r.down==1) printf("%lld",r.up);
	else if(abs(r.up)>r.down){
		printf("%lld %lld/%lld",r.up/r.down,abs(r.up)%r.down,r.down);
	}else{
		printf("%lld/%lld",r.up,r.down);
	}
	if(r.up<0) printf(")");
}

int main(){
	scanf("%lld/%lld %lld/%lld",&a.up,&a.down,&b.up,&b.down);
	ShowResult(a);
	printf(" + ");
	ShowResult(b);
	printf(" = ");
	ShowResult(Add(a,b));
	printf("\n");
	
	ShowResult(a);
	printf(" - ");
	ShowResult(b);
	printf(" = ");
	ShowResult(Minu(a,b));
	printf("\n");
	
	ShowResult(a);
	printf(" * ");
	ShowResult(b);
	printf(" = ");
	ShowResult(Multi(a,b));
	printf("\n");
	
	ShowResult(a);
	printf(" / ");
	ShowResult(b);
	printf(" = ");
	if(b.up==0) printf("Inf");
	else ShowResult(Divide(a,b));
	return 0;
}
