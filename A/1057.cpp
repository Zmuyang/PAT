#include <iostream>
#include <stack>
#define lowbit(i) ((i)&(-i))   //树状数组不可缺少 
using namespace std;
const int maxn=100010;
int c[maxn];
stack<int> st;

void update(int x,int y){
	for(int i=x;i<maxn;i+=lowbit(i)){
		c[i]+=y;
	}
}

int getsum(int x){
	int sum(0);
	for(int i=x;i>=1;i-=lowbit(i)){
		sum+=c[i];
	}
	return sum;
}

void PeekMedian(){
	int left(1),right(maxn),mid,k=(st.size()+1)/2;
	while(left<right){
		mid=(left+right)/2;
		if(getsum(mid)>=k){
			right=mid;
		}else{
			left=mid+1;
		}
	}
	cout << left << endl;
}

 
int main(){
	int n , temp;
	cin >> n;
	char S[13];
	for(int i=0;i<n;i++){
		scanf("%s",S);
		if(S[1]=='u'){
			scanf("%d",&temp);
			st.push(temp);
			update(temp,1);
		}else if(S[1]=='o'){
			if(st.empty()){
				printf("Invalid\n");
			}else{
				update(st.top(),-1);
				printf("%d\n",st.top());
				st.pop();
			}
		}else{
			if(st.empty()){
				printf("Invalid\n");
			}else{
				PeekMedian();
			}
		}
	}
	return 0;
}
