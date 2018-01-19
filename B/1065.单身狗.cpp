#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

int main(){
	int N,a,A,M;
	cin >> N;
	vector<int> Couple(100000,-1);
	for(int i=0;i<N;i++){
		cin >> A >> a;
		Couple[A]=a;
		Couple[a]=A;
	}
	cin >> M;
	vector<int> n(M),number(100000);
	for(int i=0;i<M;i++){
		cin >> n[i];
		if(Couple[n[i]]!=-1) number[Couple[n[i]]]=1;
	}
	set<int> s;
	for(int i=0;i<M;i++){
		if(!number[n[i]]){
			s.insert(n[i]);
		}
	} 
	cout << s.size() << endl;
	for(auto x=s.begin();x!=s.end();x++){
		if(x!=s.begin()) cout << " ";
		printf("%05d",*x);
	}
	return 0;
}
