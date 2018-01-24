#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct node {
	string  N;
	int H;
}; 

int cmp(struct node a, struct node b){
	return a.H!=b.H?a.H>b.H:a.N<b.N;
}

int main(){
	int n,k,m;
	cin >> n >> k;
	vector<node> stu(n);
	for(int i=0;i<n;i++){
		cin >> stu[i].N;
		cin >> stu[i].H;
	}
	sort(stu.begin(),stu.end(),cmp);
	int t(0),row=k;
	while(row){
		if(row==k){
			m=n-n/k*(k-1);
		}else{
			m=n/k;
		}
		vector<string> stemp(m);
		stemp[m/2]=stu[t].N;
		int j=m/2-1;
		for(int i=t+1;i<t+m;i=i+2){
			stemp[j--]=stu[i].N;
		}
		j=m/2+1;
		for(int i=t+2;i<t+m;i+=2){
			stemp[j++] = stu[i].N;
		}
		cout << stemp[0];
		for(int i=1;i<m;i++) cout << " " << stemp[i];
		cout << endl;
		t=t+m;
		row--;
	}
	return 0;
}

