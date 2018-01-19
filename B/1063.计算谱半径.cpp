#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int N;
	cin >> N;
	float M(0);
	for(int i=0;i<N;i++){
		float a,b,c;
		scanf("%f%f",&a,&b);
		c = sqrt(a*a+b*b);
		M = c>M?c:M;
	}
	printf("%.2f",M);
	return 0;
}
