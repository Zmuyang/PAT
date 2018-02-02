#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int maxNode=1111;
int N,M,K,query,q;  //窗口数，黄线内人数，查询人数 
int ConvertToMinute(int h,int m){   //时间转换 
	return h*60+m;
}

struct Win{
	int endTime,popTime;  //窗口当前队伍的最后服务时间、队首客户的服务结束时间 
	queue<int> q; //队列 
}win[20];

int ans[maxNode],needTime[maxNode];  //服务结束时间和服务需要时间 

int main(){
	int inIndex(0);   //当前第一个未入队的客户编号 
	cin >> N >> M >> K >> query;
	for(int i=0;i<K;i++){
		cin >> needTime[i];
	}
	for(int i=0;i<N;i++){
		win[i].popTime = win[i].endTime = ConvertToMinute(8,0);
	}
	for(int i=0;i<min(N*M,K);i++){
		win[inIndex%N].q.push(inIndex);
		win[inIndex%N].endTime+= needTime[inIndex];
		if(inIndex<N){
			win[inIndex].popTime=needTime[inIndex];
		}
		ans[inIndex] = win[inIndex%N].endTime;
		inIndex++;
	}
	for(;inIndex<K;inIndex++){   //黄线外的客户 
		int idx=-1,minPopTime=1<<30;  //1<<30 最大 
		for(int i=0;i<N;i++){
			if(win[i].popTime<minPopTime){
				idx=i;
				minPopTime=win[i].popTime;
			}
		}
		win[idx].q.pop(); //队首客户离开 
		win[idx].q.push(inIndex); //黄线外排队客户依次入队 
		win[idx].endTime += needTime[inIndex];//更新该窗口队列的服务结束时间 
		win[idx].popTime += needTime[win[idx].q.front()];//更新窗口队首时间 
		ans[inIndex]=win[idx].endTime;
	}
	for(int i=0;i<query;i++){
		cin >> q;  //查询客户编号 
		if(ans[q-1]-needTime[q-1]>=ConvertToMinute(17,0)){
			cout << "Sorry" << endl;
		}else{
			printf("%02d:%02d\n",ans[q-1]/60,ans[q-1]%60);
		}
	}
	return 0;
}
