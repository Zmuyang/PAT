#include <iostream>
using namespace std;

int a[10001]={0},b[100001];

int main(){
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		scanf("%d",&b[i]);
		a[b[i]]++;
	}
	for(int i=0;i<N;i++){
		if(a[b[i]]==1){
			cout << b[i];
			return 0;
		}
	}
	cout << "None";
	return 0;
}
