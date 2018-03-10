#include <iostream>
#include <algorithm>
using namespace std;
int course[1010]={0};
int isRoot[1010]={0};
int father[1010];

int findFather(int x){
	int a=x;
	while(x!=father[x]){
		x=father[x];
	}
	
	//Â·¾¶Ñ¹Ëõ
	while(a!=father[a]){
		int z=a;
		a=father[a];
		father[z]=x;
	} 
	return x;
}

void Union(int a,int b){
	int faA=findFather(a);
	int faB=findFather(b);
	if(faA!=faB){
		father[faA]=faB;
	}
}

void Init(int n){
	for(int i=1;i<=n;i++){
		father[i]=i;
	}
}

bool CMP(int a,int b){
	return a>b;
}

int main(){
	int n,k,h;
	cin >> n;
	Init(n);
	for(int i=1;i<=n;i++){
		scanf("%d:",&k);
		for(int j=0;j<k;j++){
			cin >> h;
			if(course[h]==0) course[h]=i;
			Union(i,findFather(course[h]));
		}
	}
	for(int i=1;i<=n;i++){
		isRoot[findFather(i)]++;
	}
	int ans(0);
	for(int i=1;i<=n;i++){
		if(isRoot[i]!=0) ans++;
	}
	cout << ans << endl;
	sort(isRoot+1,isRoot+n+1,CMP);
	for(int i=1;i<=ans;i++){
		cout << isRoot[i];
		if(i<ans) cout << " ";
	}
	return 0;
}

