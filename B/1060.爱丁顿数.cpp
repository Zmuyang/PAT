#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

bool cmp(int a ,int b){
	return a>b;
}

int main(){
	int N;
	cin >> N;
	int a[100001];
	for(int i=1;i<=N;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+N+1,cmp);
	int cnt(0),M(1);
	while(cnt<=N&&a[M]>M){
		cnt++;
		M++;
	}
	printf("%d",cnt);
	return 0;
}
