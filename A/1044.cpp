#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
vector<int> sum,result;
int N,M;

void Func(int i,int& j,int& temp){
	int L=i,R=N;
	while(L<R){
		int mid = (L+R)/2;
		if(sum[mid]-sum[i-1]>=M){
			R=mid;
		}else{
			L=mid+1;
		} 
	}
	j=R;
	temp=sum[j]-sum[i-1]; 
} 

int main(){
	cin >> N >> M;
	sum.resize(N+1);
	for(int i=1;i<=N;i++){
		scanf("%d",&sum[i]);
		sum[i]+=sum[i-1];
	}
	int min = sum[N];
	for(int i=1;i<=N;i++){
		int j,temp;
		Func(i,j,temp);
		if(temp>min){
			continue;
		}
		if(temp>=M){
			if(temp<min){
				result.clear();
				min=temp;
			}
			result.push_back(i); 
			result.push_back(j); 
		}
	}
	for(int i=0;i<result.size();i+=2){
		printf("%d-%d\n",result[i],result[i+1]);
	}
	return 0;
}
