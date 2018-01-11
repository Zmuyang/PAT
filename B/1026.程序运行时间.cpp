#include <iostream>

using namespace std;

int main(){
	int F,E,R(0),H(0),M(0),s(0);
	cin >> F >> E;
	R = (E-F+50)/100 ;
	H=R/3600;
	R=R%3600;
	M=R/60;
	s=R%60;
	printf("%02d:%02d:%02d",H,M,s);
	return 0; 
} 
