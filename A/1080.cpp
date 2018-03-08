#include <iostream>
#include <algorithm>
using namespace std;

struct STU{
	int ID;
	int GE;
	int GI;
	int R;
	int C[6];
	int sum;
}stu[40010];

struct SCH{
	int MAXnum;
	int NOWnum;
	int LASTstu;
	int index[40010];
}sch[110];

int cmp(STU a,STU b){
	if(a.sum!=b.sum) return a.sum>b.sum;
	else return a.GE>b.GE;
}

int cmpID(int a,int b){
	return stu[a].ID<stu[b].ID;
}

int main(){
	int N,M,K;
	cin >> N >> M >> K;
	for(int i=0;i<M;i++){
		sch[i].NOWnum=0;
		cin >> sch[i].MAXnum;
		sch[i].LASTstu=-1; 
	}
	
	for(int i=0;i<N;i++){
		scanf("%d%d",&stu[i].GE,&stu[i].GI);
		stu[i].sum=stu[i].GE+stu[i].GI;
		stu[i].ID=i;
		for(int j=0;j<K;j++){
			scanf("%d",&stu[i].C[j]);
		}
	}
	sort(stu,stu+N,cmp);
	
	for(int i=0;i<N;i++){
		if(i>0&&stu[i].sum==stu[i-1].sum&&stu[i].GE==stu[i-1].GE){
			stu[i].R=stu[i-1].R;
		}else{
			stu[i].R=i;
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<K;j++){
			int choice=stu[i].C[j];
			int num=sch[choice].NOWnum;
			int last=sch[choice].LASTstu;
			if(num<sch[choice].MAXnum || (last!=-1&&stu[i].R==stu[last].R)){
				sch[choice].index[num]=i;
				sch[choice].LASTstu=i;
				sch[choice].NOWnum++;
				break;
			}
		}
	}
	for(int i=0;i<M;i++){
		if(sch[i].NOWnum>0){
			sort(sch[i].index,sch[i].index+sch[i].NOWnum,cmpID);
			for(int j=0;j<sch[i].NOWnum;j++){
				printf("%d",stu[sch[i].index[j]].ID);
				if(j<sch[i].NOWnum-1) printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
