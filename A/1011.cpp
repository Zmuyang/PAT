#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

double Max(double a,double b, double c);

int main(){
	map<string,double> a;
	char s[3];
	double temp(1);
	for(int i=0;i<3;i++){
		double t;
		cin >> a["W"] >> a["T"] >> a["L"];
		t= Max(a["W"],a["T"],a["L"]);
		temp*=t;
		if(t == a["W"]) s[i]='W';
		if(t == a["T"]) s[i]='T';
		if(t == a["L"]) s[i]='L';
	} 
	temp = (temp*0.65-1)*2;
	printf("%c %c %c ",s[0],s[1],s[2]); 
	printf("%.2f",temp); 
} 

double Max(double a,double b, double c){
	double M = max(a,b);
	return max(M,c);
}
