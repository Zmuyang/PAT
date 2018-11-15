#include <iostream>
#include <algorithm>
#include <cctype>
#include <cmath>
using namespace std;

long long Convert(string s,long long radix){
	long long sum=0;
	int index=0,temp=0;
	for(auto it=s.rbegin() ;it!=s.rend() ;it++){
		temp = isdigit(*it) ? *it -'0' : *it -'a' + 10;
		sum += temp * pow(radix,index++);
	}
	return sum;
}

long long Find_radix(string s,long long num){
	long long it = *max_element(s.begin() ,s.end() );
	long long Low = isdigit(it) ? it-'0' : it-'a'+10;
	Low+=1;
	long long High= max(Low,num);
	while(Low<=High){
		long long mid = Low + (High - Low)/2;
		long long n=Convert(s,mid);
		if(n==num) return mid;
		else if(n<0||n>num) High=mid+-1;
		else Low=mid+1;
	}
	return -1;
}

int main(){
	string n1,n2;
	long long tag=0,radix=0,result=0;
	cin >> n1 >> n2 >> tag >> radix;
	result = tag==1 ? Find_radix(n2,Convert(n1,radix)) : Find_radix(n1,Convert(n2,radix));
	if(result==-1) printf("Impossible");
	else printf("%lld",result);
	return 0;
}
