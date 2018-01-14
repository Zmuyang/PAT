#include <iostream>
#include <vector>

using namespace std;

struct St{
	long long int Id;
	int t;
	int p;
};

int main(){
	int n,N;
	cin >> n;
	vector<St> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i].Id;
		cin >> a[i].t;
		cin >> a[i].p;
	}
	cin >> N;
	vector<int> s(N);
	for(int i=0;i<N;i++){
		cin >> s[i];
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<n;j++){
			if(s[i] == a[j].t){
				cout << a[j].Id << " " << a[j].p << endl;
			}
		}
	}
	return 0;
}
