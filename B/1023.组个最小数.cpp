#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> a(10);
	int book(0);
	
	for(int i=0;i<10;i++){
		cin >> a[i];
	}
	
	for(int i=1;i<10;i++){
		if(a[i]!=0) {
			cout << i ;
			a[i]--;
			break;
		}
	}
	for(int i=0;i<10;i++){
		if(a[i]!=0){
			for(int j=0;j<a[i];j++){
				cout << i;
			}
		}
	}
	return 0;
}
