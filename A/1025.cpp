#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct STU{
	string ID;
	int score,LR,LN;
}stu[30010];

int CMP(struct STU a,struct STU b){
	if(a.score!=b.score) return a.score>b.score;
	else return a.ID<b.ID;
}

int main(){
	int N,K,sum(0);
	cin >> N;
	for(int i=1;i<=N;i++){
		cin >> K;
		for(int j=0;j<K;j++){
			cin >> stu[sum].ID >> stu[sum].score;
			stu[sum].LN=i;
			sum++;
		} 
		sort(stu+sum-K,stu+sum,CMP);
		stu[sum-K].LR=1;
		for(int j=sum-K+1;j<sum;j++){
			if(stu[j].score==stu[j-1].score){
				stu[j].LR=stu[j-1].LR;
			}else{
				stu[j].LR=j+1-(sum-K);
			}
		}
	}
	cout << sum << endl;
	sort(stu,stu+sum,CMP);
	int r=1;
	for(int i=0;i<sum;i++){
		if(i>0 && stu[i].score!=stu[i-1].score){
			r=i+1;
		}
		cout << stu[i].ID << " ";
		printf("%d %d %d\n",r,stu[i].LN,stu[i].LR);
	}
	return 0;
}
