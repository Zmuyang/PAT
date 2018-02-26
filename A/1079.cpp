#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct node{
	double data;
	vector<int> child;
};

vector<node> v;
double ans(0.0),p,r;

void DFS(int index, int depth){
	if(v[index].child.size()==0){
		ans+=v[index].data*pow(1+r,depth);
		return;
	}
	for(int i=0;i<v[index].child.size();i++){
		DFS(v[index].child[i],depth+1);
	}
}
int main(){
	int n,k,c;
	cin >> n >> p >> r;
	r/=100;
	v.resize(n);
	for(int i=0;i<n;i++){
		cin >> k;
		if(k==0) cin >> v[i].data;
		else{
			for(int j=0;j<k;j++){
				cin >> c;
				v[i].child.push_back(c);
			}
		}
	}
	DFS(0,0);
	printf("%.1f",ans*p);
	return 0;
}
