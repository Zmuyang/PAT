#include <iostream>
#include <map>
using namespace std;

int main(){
	int M,N,P;
	cin >> M >> N >> P;
	string s;
	map<string,int> mark;
	bool flag = false;
	for(int i=1;i<=M;i++){
		cin >> s;
		if(mark[s]==1) P+=1;
		if(i==P&&mark[s]==0){
			mark[s]=1;
			cout << s << endl;
			flag=true;
			P+=N;
		}
	}
	if(!flag) cout << "Keep going...";
	return 0;
}

/*   测试点3不通过 
struct node{
	string s;
	int mark;
};

int main(){
	int N,M,P,cnt(0);
	cin >> N >> M >> P;

	vector<node> a(N);
	for(int i=0;i<N;i++){
		 cin >> a[i].s;
		 a[i].mark = 0;
	}
	if(P>N){
		cout << "Keep going..." << endl;
		return 0;
	}
	for(int i=1;i<N;i++){
		if(a[cnt].s!=a[i].s){
			a[++cnt]=a[i];
		}
	}
	for(int i=P-1;i<=cnt;i+=M){
		if(a[i].mark==1){
			i++;
		}
		cout << a[i].s << endl;
		a[i].mark=1;
	}
	return 0;
} 
*/
