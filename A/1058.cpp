#include <cstdio>
using namespace std;

int main(){
	long long int G,S,K,sum(0);
	for(int i=0;i<2;i++){
		scanf("%lld.%lld.%lld",&G,&S,&K);
		sum +=(G*17*29+S*29+K);
	}
	G=sum/(17*29);
	S=sum%(17*29)/29;
	K=sum%(17*29)%29;
	printf("%lld.%lld.%lld",G,S,K);
	return 0;
} 
