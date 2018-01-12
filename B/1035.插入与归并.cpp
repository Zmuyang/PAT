#include <iostream>
#include <algorithm>

using namespace std;

int cmp(int a,int b){
	return a<b;
} 

int main(){
	int N,x(0),y(0);
	cin >> N;
	int *a = new int [N];
	int *b = new int [N];
	
	for(int i=0;i<N;i++) {
		cin >> a[i];
	}
	for(int i=0;i<N;i++){
		cin >> b[i];
	}
	
	for(;x<N-1 && b[x]<= b[x+1];x++);
	for(y=x+1;y<N && a[y] == b[y]; y++);
	
	if(y == N){
		cout << "Insertion Sort" << endl;
		sort(a,a+x+2,cmp);
	}else{
		cout << "Merge Sort" << endl;
		int k=1;
		int flag=1;
		while(flag){
			flag=0;
			for(int i=0;i<N;i++){
				if(a[i]!=b[i]) flag = 1;
			}
			k*=2;
			for(int i=0;i<N/k;i++){
				sort(a+i*k,a+(i+1)*k,cmp);
			}
			sort(a+N/k*k,a+N,cmp);
		}
	}
	for(int i=0;i<N-1;i++) cout << a[i] << " ";
	cout << a[N-1];
	delete [] a;
	delete [] b;
	return 0;
}
