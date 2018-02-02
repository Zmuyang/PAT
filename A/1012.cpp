#include <iostream> 
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

struct ST{
	int ID,grade[4];
}stu[3000];

char course[4]={'A','C','M','E'};
int Rank[1000000][4]={0} , index;

bool cmp(ST a, ST b){
	return a.grade[index] > b.grade[index];
} 

int main(){
	int N,M;
	cin >> N >> M;
	for(int i=0;i<N;i++){
		cin >> stu[i].ID >> stu[i].grade[1] >> stu[i].grade[2] >> stu[i].grade[3];
		stu[i].grade[0] = stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3];
	}
	for(index=0;index<4;index++){
		sort(stu,stu+N,cmp);
		Rank[stu[0].ID][index] = 1;
		for(int i=1;i<N;i++){
			if(stu[i].grade[index] == stu[i-1].grade[index]){
				Rank[stu[i].ID][index] = Rank[stu[i-1].ID][index];
			}else{
				Rank[stu[i].ID][index] = i+1;
			}
		}
	}
	int query;
	for(int i=0;i<M;i++){
		cin >> query;
		if(Rank[query][0]==0){
			cout << "N/A" << endl;
		}else{
			int temp(0);
			for(int j=0;j<4;j++){
				if(Rank[query][j]<Rank[query][temp]){
					temp=j;
				}
			}
			cout << Rank[query][temp] << " " << course[temp] << endl;
		}
	}
	return 0;
}
