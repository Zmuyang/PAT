#include <iostream>
#include <vector>
using namespace std;

struct node{
	int mark=0;
	string ID;
	string P;
};

int main(){
	int N,cnt(0);
	cin >> N;
	vector<node> arr(N);
	for(int i=0;i<N;i++){
		cin >> arr[i].ID >> arr[i].P ;
		for(int j=0;j<arr[i].P.size();j++){
			if(arr[i].P[j]=='1'){
				arr[i].P[j]='@';
				arr[i].mark=1;
			}
			if(arr[i].P[j]=='0'){
				arr[i].P[j]='%';
				arr[i].mark=1;				
			}
			if(arr[i].P[j]=='l'){
				arr[i].P[j]='L';
				arr[i].mark=1;				
			}
			if(arr[i].P[j]=='O'){
				arr[i].P[j]='o';
				arr[i].mark=1;				
			}
		}
		if(arr[i].mark==1) cnt++;
	}
	if(cnt==0){
		if(N==1){
			cout << "There is 1 account and no account is modified" << endl;
			return 0;
		}else{
			printf("There are %d accounts and no account is modified\n",N);
			return 0;
		}
	}
	cout << cnt << endl;
	for(int i=0;i<N;i++){
		if(arr[i].mark==1){
			cout << arr[i].ID << " " << arr[i].P << endl;
		}
	}
	return 0;
} 
