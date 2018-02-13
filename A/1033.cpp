#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn(510);
const int inf(1000000000);
struct station {
	double price,dis;
}st[maxn];

bool cmp(station a,station b){
	return a.dis<b.dis;
} 

int main(){
	int n;
	double T,D,AVG;
	scanf("%lf%lf%lf%d",&T,&D,&AVG,&n); 
	for(int i=0;i<n;i++){
		cin >> st[i].price >> st[i].dis;
	}
	st[n].price=0;
	st[n].dis=D;    //放置终点
	sort(st,st+n,cmp);
	if(st[0].dis!=0){
		cout << "The maximum travel distance = 0.00" << endl;
	}else{
		int now(0); //当前所处的加油站编号
		double ans,t,MAX=T*AVG; //总花费，当前油量，及满油行驶距离
		while(now<n){   //每次循环选出下一站加油站的位置 
			int k(-1);
			double priceMIN=inf;
			for(int i=now+1;i<=n&&st[i].dis-st[now].dis<=MAX;i++){
				if(st[i].price<priceMIN){
					priceMIN=st[i].price;
					k=i;
					if(priceMIN<st[now].price){
						break;
					}
				}
			}
			if(k==-1) break; //满油状态下无法找到加油站，退出循环
			double need=(st[k].dis-st[now].dis)/AVG; //从当前站点到下一个站点需要的油量
			if(priceMIN<st[now].price){
				if(t<need){
					ans+=(need-t)*st[now].price;
					t=0;
				}else{
					t-=need;
				}
			} else{
				ans+=(T-t)*st[now].price;
				t=T-need;
			}
			now=k; //到达K加油站，进入下一个循环 
		} 
		if(now==n){ //能到达终点 
			printf("%.2f\n",ans);
		}else{  //不能 
			printf("The maximum travel distance = %.2f\n",st[now].dis+MAX);
		}
	}
	return 0;
}
