#include <iostream>
#include <cstring>
using namespace std;

const int maxn(1010);
string S;
int dp[maxn][maxn];
int main(){
	getline(cin,S);
	int len = S.size(),ans(1);
	memset(dp,0,sizeof(dp));
	for(int i=0;i<len;i++){
		dp[i][i]=1;
		if(i<len-1){
			if(S[i]==S[i+1]){
				dp[i][i+1]=1;
				ans=2;
			}
		}
	} 
	for(int L=3;L<=len;L++){
		for(int i=0;i+L-1<len;i++){
			int j=i+L-1;
			if(S[i]==S[j]&&dp[i+1][j-1]==1){
				dp[i][j]=1;
				ans=L;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
