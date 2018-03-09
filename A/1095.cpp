#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int num(0);  //有效记录的条数
map<string,int> ParkTime; 

const int maxn(10010);
struct CAR{
	char ID[8];
	int time;
	char status[4];
}cars[maxn],valid[maxn];

int TIME(int H,int M, int S){
	return H*3600+M*60+S;
}

bool cmpByIDAndtime(CAR a,CAR b){
	if(strcmp(a.ID,b.ID)) return strcmp(a.ID,b.ID)<0;
	else{
		return a.time<b.time;
	}
} 

bool cmpByTime(CAR a,CAR b){
	return a.time<b.time;
}

int main(){
	int n,k;
	cin >> n >> k;
	for(int i=0;i<n;i++){
		int h,m,s;
		scanf("%s %d:%d:%d %s",cars[i].ID,&h,&m,&s,cars[i].status);
		cars[i].time=TIME(h,m,s);
	}
	sort(cars,cars+n,cmpByIDAndtime);
	
	int maxTime(-1);
	for(int i=0;i<n-1;i++){
		if( !strcmp(cars[i].ID,cars[i+1].ID) && !strcmp(cars[i].status,"in") && !strcmp(cars[i+1].status,"out") ){
			valid[num++]=cars[i];
			valid[num++]=cars[i+1];
			int inTime=cars[i+1].time-cars[i].time;
			if(ParkTime.count(cars[i].ID)==0){
				ParkTime[cars[i].ID]=0;
			}
			ParkTime[cars[i].ID]+=inTime;
			maxTime=max(maxTime,ParkTime[cars[i].ID]);
		}
	}
	
	sort(valid,valid+num,cmpByTime);
	
	int now(0),numCar(0);
	for(int i=0;i<k;i++){
		int h,m,s;
		scanf("%d:%d:%d",&h,&m,&s);
		int time=TIME(h,m,s);
		while(now<num&&valid[now].time<=time){
			if(!strcmp(valid[now].status,"in")) numCar++;
			else numCar--;
			now++;
		}
		printf("%d\n",numCar);
	}
	
	map<string,int>::iterator it;
	for(it=ParkTime.begin();it!=ParkTime.end();it++){
		if(it->second==maxTime){
			printf("%s ",it->first.c_str());
		}
	}
	
	printf("%02d:%02d:%02d",maxTime/3600,maxTime%3600/60,maxTime%60);
	return 0;
}
