#include <iostream>
#include <algorithm> //sort

using namespace std;

int cmp(int a,int b) {return a > b;} // 降序排序 

int main(){
	int n(0);
	cin >> n;
	int *a = new int[n];   //C++ 
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int t;
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		t=a[i];
		while(t!=1 && t!=999){
			if(t%2==0){
				t=t/2;
			}else{
				t=(3*t+1)/2;
			}
			for(int j=0;j<n;j++){
				if(t==a[j] && j!=i){
					a[j]=999;
				}
			}
		}
	}
	sort(a,a+n,cmp);
	int temp(0);
	for(int i=n-1;i>=0;i--){
		if(a[i]!=999){
			temp=i;   // temp是第一个不等于999的下标 
		}
	}
	for(int i=temp;i<n-1;i++){
		cout << a[i] << " ";
	}
	cout << a[n-1];
	delete [] a; // c++ 
	return 0;
}
