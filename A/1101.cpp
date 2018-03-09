#include <iostream>
#include <algorithm>
using namespace std;

const int maxn(100000);
int x[maxn],y[maxn],z[maxn];

int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> x[i];
		y[i]=x[i];
	}
	sort(x,x+n);
	int MAX(0),cnt(0);
	for(int i=0;i<n;i++){
		if(x[i]==y[i]&&y[i]>MAX){
			z[cnt++]=y[i];
		}
		if(y[i]>MAX) MAX=y[i];
	}
	cout << cnt << endl;
	for(int i=0;i<cnt;i++){
		if(i==0) printf("%d",z[i]);
		else printf(" %d",z[i]);
	}
	printf("\n");
	return 0;
}
