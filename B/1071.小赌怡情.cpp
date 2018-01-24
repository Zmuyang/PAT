#include <iostream>
#include <vector>
using namespace std;

int main(){
	int N,n;
	cin >> N >> n;
	for(int i=0;i<n;i++){
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		if(c>N){
			cout << "Not enough tokens.  Total = " << N << "." << endl;
			continue;
		}
		if(a>d&&b==0){
			printf("Win %d!  Total = %d.\n",c,N+=c);
			continue;
		}
		if(a>d&&b==1){
			printf("Lose %d.  Total = %d.\n",c,N-=c);
			if(N==0){
				printf("Game Over.\n");
				break;
			}
			continue;
		}
		if(a<d&&b==1){
			printf("Win %d!  Total = %d.\n",c,N+=c);
			continue;
		}
		if(a<d&&b==0){
			printf("Lose %d.  Total = %d.\n",c,N-=c);
			if(N==0){
				printf("Game Over.\n");
				break;
			}
			continue;
		}
	}
	return 0;
} 
