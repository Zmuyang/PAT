#include <cstdio>
#include <stack>
using namespace std;

int Check[1003];

int main(){
	stack<int> s;
	int M,N,K;
	scanf("%d %d %d",&M,&N,&K);
	while(K--){
		while(!s.empty()){
			s.pop();
		}
		for(int i=1;i<=N;i++){
			scanf("%d",&Check[i]);
		}
		int cnt=1;
		bool flag=true;
		for(int i=1;i<=N;i++){
			s.push(i);
			if(s.size()>M){
				flag=false;
				break;
			}
			while(!s.empty()&&s.top()==Check[cnt]){
				s.pop();
				cnt++;
			}
		}
		if(s.empty()&&flag){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}
