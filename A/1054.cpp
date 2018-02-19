#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int main(){
	int M,N;
	cin >> M >> N;
	map<int,int> arr;
	int half = M*N/2;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			int temp;
			scanf("%d",&temp);
			arr[temp]++;
			if(arr[temp]>half){
				printf("%d\n",temp);
				return 0;
			}
		}
	}
	return 0;
}
