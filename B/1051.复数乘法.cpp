#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main(){
	double r1,p1,r2,p2;
	cin >> r1 >> p1 >> r2 >> p2;
	double A,B;
	A= r1*r2*(cos(p1)*cos(p2)-sin(p1)*sin(p2));
	B= r1*r2*(cos(p1)*sin(p2)+cos(p2)*sin(p1));
	if(A+0.01>=0&&A<0){
		printf("0.00");
	}else{
		printf("%.2f",A);
	}
	if(B>=0){
		printf("+%.2fi",B);
	}else if(B+0.01>=0&&B<0){
		printf("+0.00i");
	}else{
		printf("%.2fi",B);
	}
	return 0;
}
