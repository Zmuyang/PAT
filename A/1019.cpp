#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int N,b;
	vector<int> arr,temp;
	cin >> N >> b;
	if(N==0){
		cout << "Yes" << endl;
		cout << "0";
		return 0;
	}
	while(N){
		arr.push_back(N%b);
		N/=b;
	}
	temp = arr;
	reverse(arr.begin(),arr.end());
	if(temp==arr){
		cout <<"Yes"<<endl;
	}else{
		cout << "No"<<endl;
	}
	for(int i=0;i<arr.size();i++){
		cout << arr[i];
		if(i!=arr.size()-1) cout << " ";
	}
	return 0;
}
