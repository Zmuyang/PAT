#include <iostream>
#include <vector>

using namespace std;

int main(){
	int N,ID,score;
	cin >> N;
	vector<int> a(N);
	for(int i=0;i<N;i++){
		cin >> ID >> score;
		a[ID]+=score;
	}
	int MAX = a[1];
	int t(1);
	for(int i=1;i<N;i++){
		if(MAX<a[i]){
			MAX=a[i];
			t=i;
		}
	}
	cout << t << " "<< MAX;
	return 0;
}
