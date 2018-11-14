#include <iostream>
#include <vector>
using namespace std;


int main(){
	int M,L=0;
	bool flag=false;
	cin >> M;
	vector<int> Dpi(M);
	vector<int> arr(M);
	for(int i=0;i<M;i++){
		cin >> arr[i];
		if(arr[i]>=0) flag=true;
	}
	Dpi[0]=arr[0];
	for(int i=1;i<M;i++){
		if(arr[i]<Dpi[i-1]+arr[i]){
			Dpi[i]=Dpi[i-1]+arr[i];
		}else{
			Dpi[i]=arr[i];
		}
	}
	int k=0;
	for(int i=1;i<M;i++){
		if(Dpi[k]<Dpi[i]) k=i;
	}
	int sum=Dpi[k];
	for(int i=k;i>=0;i--){
		sum-=arr[i];
		if(sum==0){
			L=i;
			break;
		}
	}
	if(!flag) cout << 0 << " " << arr[0] << " " << arr[M-1] << endl;
	else cout << Dpi[k] << " " << arr[L] << " " << arr[k] << endl;
	return 0;
} 
