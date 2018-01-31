#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

long long Map[256] ; //0-9 , a-z
long long inf = (1LL << 63) - 1;  // 取long long 的最大值 2^63-1;
char N1[20],N2[20],temp[20];
int tag,radix; 

void init();
long long convertNum10(char a[],long long radix,long long t);  //a转换为10进制 ， t为上界 
int cmp(char N2[],long long radix, long long t);  //N2的10进制与t比较 
long long binarySearch(char N2[],long long left,long long right, long long t);  //二分求解N2的进制 
int findlargestDigit(char N2[]); //求最大位数 

int main(){
	init();
	cin >> N1 >> N2 >> tag >> radix;
	if(tag==2){
		swap(N1,N2);
	}
	long long t = convertNum10(N1,radix,inf);  //N1从radix进制转换为十进制 
	long long low = findlargestDigit(N2);      //找到N2中数位最大的位+1，当成二分下界
	long long high = max(low,t)+1 ;        //上界
	long long ans =  binarySearch(N2,low,high,t);  //二分
	if(ans==-1){
		cout << "Impossible" << endl;
	} else{
		printf("%lld",ans);
	}
	return 0;
}
 
int findlargestDigit(char N2[]){
	int ans=-1;
	for(int i=0;i<strlen(N2);i++){
		if(Map[N2[i]]>ans){
			ans = Map[N2[i]];
		}
	}
	return ans+1; //最大的数位为ans，说明进制数的底线是ans+1 
}

long long binarySearch(char N2[],long long left,long long right, long long t){
	long long mid;
	while(left<=right){
		mid = (left+right)/2;
		int flag = cmp(N2,mid,t);  //判断N2转换为10进制后与t比较 
		if(flag==0){
			return mid;            // 找到解，返回mid 
		}else if(flag==-1){
			left = mid+1;
		}else{
			right = mid - 1;
		}
	}
	return -1; //解不存在 
}

int cmp(char N2[],long long radix, long long t){
	long long num = convertNum10(N2,radix,t);
	if(num<0){
		return 1;    //溢出，N2>t 
	}
	if(t>num){
		return -1; //t较大，返回-1； 
	}else if(t==num){
		return 0;   //相等 
	}else{
		return 1; //num较大，返回1 
	}
}

long long convertNum10(char a[],long long radix,long long t){
	long long ans(0);
	for(int i=0;i<strlen(a);i++){
		ans = ans * radix + Map[a[i]]; //进制转换
		if(ans<0 || ans>t){   //溢出或超过N1的十进制 
			return -1;
		} 
	}
	return ans;
}
void init(){
	for(char c = '0';c<='9';c++){
		Map[c] = c-'0';
	}
	for(char c='a';c<='z';c++){
		Map[c] = c - 'a' + 10;
	}
} 
