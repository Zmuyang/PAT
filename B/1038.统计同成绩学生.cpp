#include <iostream>
#include <vector>

using namespace std;

struct st{
	int score;
}temp[101];

int main(){
	for(int i=0;i<101;i++){
		temp[i].score=0;
	}
	int N,n;
	cin >> N;
	for(int i=0;i<N;i++){
		int s;
		cin >>s;
		temp[s].score++;
	}
	cin >> n;
	vector<int> a(n);
	int num = n-1;
	for(int i=0;i<n;i++){
		cin >> a[i];
		cout << temp[a[i]].score;
		if(num){
			cout << " ";
			num--;
		}
	}
	
	return 0;
}
