
#include <vector>
#include <cstdio>
using namespace std;


int main(){
	vector<double> A(1001,0.0) , B(2001,0.0);
	int n,m,cnt(0),exp;
	double coe;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %lf",&exp,&coe);
		A[exp]=coe;
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d %lf",&exp,&coe);
		for(int j=0;j<1001;j++){
			if(A[j]!=0.0){
				B[exp+j] += A[j]*coe;
			}
		}
	}
	for(int i=2000;i>=0;i--){
		if(B[i]!=0.0){
			cnt++;
		}
	}
	printf("%d",cnt);
	for(int i=2000;i>=0;i--){
		if(B[i]!=0.0){
			printf(" %d %.1f",i,B[i]);
		}
	}
	return 0;
}
