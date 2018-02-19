#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=100010;

int age[maxn]={0};
struct Person{
	int age,worth;
	char name[10];
}ps[maxn],valid[maxn];

bool cmp(Person a,Person b){
	if(a.worth!=b.worth){
		return a.worth>b.worth;
	}else if(a.age!=b.age){
		return a.age<b.age;
	}else{
		return strcmp(a.name,b.name)<0;
	}
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%s%d%d",ps[i].name,&ps[i].age,&ps[i].worth);
	} 
	sort(ps,ps+n,cmp);
	int validNUM(0);
	for(int i=0;i<n;i++){
		if(age[ps[i].age]<100){
			age[ps[i].age]++;
			valid[validNUM++]=ps[i];
		}
	}
	int m,ageL,ageR;
	for(int i=1;i<=k;i++){
		scanf("%d%d%d",&m,&ageL,&ageR);
		printf("Case #%d:\n",i);
		int cnt(0);
		for(int j=0;j<validNUM&&cnt<m;j++){
			if(valid[j].age>=ageL&&valid[j].age<=ageR){
				printf("%s %d %d\n",valid[j].name,valid[j].age,valid[j].worth);
				cnt++;
			}
		}
		if(cnt==0){
			printf("None\n");
		}
	}
	return 0;
}
