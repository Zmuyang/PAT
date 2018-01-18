#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;
struct node{
	int ID;
	int cnt;
};
bool Func(int a){
	for(int i=2;i<=sqrt(a);i++){
		if(a%i==0) return false;
	}
	return true;
}

int main(){
	int N,n;
	cin >> N;
	vector<node> book(N);
	for(int i=0;i<N;i++){
		cin >> book[i].ID;
		book[i].cnt=2;
	}
	cin >> n;
	for(int i=0;i<n;i++){
		int x,j(0);
		cin >> x;
		for(;j<N;j++){
			if(x==book[j].ID&&book[j].cnt!=1){
				if((j+1)==1){
					printf("%04d: ",x);
					printf("Mystery Award\n");
					book[j].cnt=1;
					break;
				}else if(Func(j+1)){
					printf("%04d: ",x);
					printf("Minion\n");
					book[j].cnt=1;
					break;
				}else{
					printf("%04d: ",x);
					printf("Chocolate\n");
					book[j].cnt=1;
					break;
				}
			}else if(x==book[j].ID&&book[j].cnt==1){
				printf("%04d: ",x);
				printf("Checked\n");
				break;
			}
		}
		if(j==N){
			printf("%04d: ",x);
			printf("Are you kidding?\n");
			continue;
		}
	}
	return 0;
}
