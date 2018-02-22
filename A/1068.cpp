#include <cstdio>
#include <algorithm>
using namespace std;

int w[10010],dp[110]={0};
bool choice[10010][110],flag[10010];
bool cmp(int a,int b){
	return a>b;
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&w[i]);
	}
	sort(w+1,w+1+n,cmp);
	for(int i=1;i<=n;i++){
		for(int v=m;v>=w[i];v--){
			if(dp[v]<=dp[v-w[i]]+w[i]){
				dp[v]=dp[v-w[i]]+w[i];
				choice[i][v]=1;
			}else{
				choice[i][v]=0;
			}
		}
	}
	if(dp[m]!=m) printf("No Solution");
	else{
		int k=n,num(0),v=m;
		while(k>=0){
			if(choice[k][v]==1){
				flag[k]=true;
				v-=w[k];
				num++;
			}else{
				flag[k]=false;
			}
			k--;
		}
		for(int i=n;i>=1;i--){
			if(flag[i]==true){
				printf("%d",w[i]);
				num--;
				if(num>0) printf(" ");
			}
		}
	}
	return 0;
}
