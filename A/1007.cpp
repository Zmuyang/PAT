#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n,temp(0),sum(-1),left(0),right(0),index(0);
	bool flag=false;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
		if(arr[i]>=0) flag=true;
		temp+=arr[i];
		if(temp>sum){
			sum=temp;
			left=index;
			right=i;
		}else if(temp<0){
			temp=0;
			index=i+1;
		}
	}
	if(!flag){
		cout << 0 << " " << arr[0] << " " << arr[n-1] << endl;
		return 0;
	}else{
		cout << sum << " " << arr[left] << " " << arr[right] << endl;
	}
	return 0;
}
