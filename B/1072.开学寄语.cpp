#include <iostream>
#include <vector>
using namespace std;

int main(){
	int N,M,cnt(0),sum(0);
	cin >> N >> M;
	vector<int> a(M);
	for(int i=0;i<M;i++) cin >> a[i];
	
	for(int i=0;i<N;i++){
		string s;
		int n;
		bool c=false;
		cin >> s >> n;
		vector<bool> flag(n,false);
		vector<int> b(n);
		for(int j=0;j<n;j++){
			cin >> b[j];
			for(int x=0;x<M;x++){
				if(b[j]==a[x]){
					cnt++;
					flag[j]=true;
					c=true;
				}
			}
		}
		if(c){
			cout << s << ":" ;
			sum++;
			for(int j=0;j<n;j++){
				if(flag[j]){
					printf(" %04d",b[j]);
				}
			}
			cout << endl;
		}
	}
	cout << sum << " " << cnt;
	return 0;
} 
