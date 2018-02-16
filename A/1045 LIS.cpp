#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int Favorites[210],A[10010],dp[10010];
int main(){
	int n,m,x;
	cin >> n >> m;
	memset(Favorites,-1,sizeof(Favorites));
	for(int i=0;i<m;i++){
		scanf("%d",&x);
		Favorites[x]=i;
	}
	int L,num(0);
	cin >> L;
	for(int i=0;i<L;i++){
		scanf("%d",&x);
		if(Favorites[x]>=0){
			A[num++]=Favorites[x];
		}
	}
	//LISÄ£°å
	int ans(-1);
	for(int i=0;i<num;i++){
		dp[i]=1;
		for(int j=0;j<i;j++){
			if(A[j]<=A[i]&&dp[i]<dp[j]+1){
				dp[i]=dp[j]+1;
			}
		}
		ans=max(ans,dp[i]);
	} 
	cout << ans << endl;
	return 0;
}
