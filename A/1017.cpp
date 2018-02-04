#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;

struct Customer{
	int arrive,time;
}temp;

int cmp(struct Customer a,struct Customer b);

int main(){
	int N,M;
	cin >> N >> M;
	vector<Customer> custom;
	for(int i=0;i<N;i++){
		int h,m,s;
		scanf("%d:%d:%d %d",&h,&m,&s,&temp.time);
		if(temp.time>60) temp.time=60;
		if(h*3600+m*60+s>61200) continue;
		temp.arrive = h*3600+m*60+s;
		temp.time *=60;
		custom.push_back(temp);
	}
	sort(custom.begin(),custom.end(),cmp);
	vector<int> window(M,28800);
	double average(0.0);
	for(int i=0;i<custom.size();i++){
		int index(0),finish=window[0];
		for(int j=1;j<M;j++){
			if(finish>window[j]){
				index=j;
				finish = window[j];
			}
		}
		if(window[index]<=custom[i].arrive){
			window[index] =(custom[i].arrive + custom[i].time);  //如果顾客到达时窗口处于空闲 
		}else{
			average += (window[index]-custom[i].arrive);
			window[index] += custom[i].time;
		}
	}
	if(custom.size()==0){
		printf("0.0\n");
	}else{
		printf("%.1f\n",average/60.0/custom.size());
	}
	return 0;
	return 0;
}

int cmp(struct Customer a,struct Customer b){
	if(a.arrive!=b.arrive){
		return a.arrive<b.arrive;
	}
}
