#include <iostream>
using namespace std;

int main(){
	int arr[10001] = {0};
	int N,M,max;
	cin >> N;
	for(int i=0;i<N;i++){
		int a,b,c;
		scanf("%d-%d%d",&a,&b,&c);
		arr[a]+=c;
	}	
	max=arr[0];
	for(int i=1;i<10001;i++){
		if(arr[i]>max){
			max=arr[i];
			M=i;
		}
	}
	cout << M << " " << max << endl;
	return 0;
}
