#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
char name[40010][5];
vector<int> course[2510];
bool CMP(int a,int b){
	return strcmp(name[a],name[b])<0;
}

int main(){
	int N,K;
	cin >> N >> K;
	for(int i=0;i<N;i++){
		int cnt,temp;
		scanf("%s %d",name[i],&cnt);
		for(int j=0;j<cnt;j++){
			scanf("%d",&temp);
			course[temp].push_back(i);
		}
	}
	for(int i=1;i<=K;i++){
		printf("%d %d\n",i,course[i].size());
		sort(course[i].begin(),course[i].end(),CMP);
		for(int j=0;j<course[i].size();j++){
			printf("%s\n",name[course[i][j]]);
		}
	}
	return 0;
}
