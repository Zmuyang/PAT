#include <iostream>
#include <map>
#include <set>
using namespace std;

int main(){
	int N,M;
	cin >> N >> M;
	map<string,set<int>> ST;
	for(int i=0;i<M;i++){
		int index,amounts;
		cin >> index >> amounts;
		for(int j=0;j<amounts;j++){
			string name;
			cin >> name;
			ST[name].insert(index);
		}
	}
	for(int i=0;i<N;i++){
		string name;
		cin >> name;
		cout << name << " " << ST[name].size();
		for(auto it=ST[name].begin();it!=ST[name].end();it++){
			printf(" %d",*it);
		}
		printf("\n");
	}
	return 0;
} 
