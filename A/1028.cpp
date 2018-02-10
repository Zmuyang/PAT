#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct STU{
	int ID,grade;
	char name[10];
};
int mark(0);
int CMP(STU a,STU b){
	if(mark==1){
		return a.ID<b.ID;
	}else if(mark==2){
		return strcmp(a.name,b.name)<=0;	
	}else {
		return a.grade<=b.grade;
	}
}

int main(){
	int N;
	cin >> N >> mark;
	vector<STU> stu(N);
	for(int i=0;i<N;i++){
		scanf("%06d %s %d",&stu[i].ID,&stu[i].name,&stu[i].grade);
	}
	sort(stu.begin(),stu.end(),CMP);
	for(int i=0;i<N;i++){
		printf("%06d %s %d\n",stu[i].ID,stu[i].name,stu[i].grade);
	}
	return 0;
}
