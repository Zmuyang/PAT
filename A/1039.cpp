#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N=40010;
const int M=26*26*26*10+1;

vector<int> v[M];

int getID(char *name){
	int id(0);
	for(int i=0;i<3;i++){
		id = id*26+(name[i]-'A');
	}
	id=id*10+(name[3]-'0');
	return id;
}

int main(){
	char name[5];
	int n,k;
	cin >> n >> k;
	for(int i=0;i<k;i++){
		int course , x;
		cin >> course >> x;
		for(int j=0;j<x;j++){
			cin >> name;
			int id = getID(name);
			v[id].push_back(course);
		}
	}
	
	for(int i=0;i<n;i++){
		cin >> name;
		int id=getID(name);
		sort(v[id].begin(),v[id].end());
		cout << name << " " << v[id].size();
		for(int j=0;j<v[id].size();j++){
			printf(" %d",v[id][j]);
		}
		cout << endl;
	}
	return 0;
}
