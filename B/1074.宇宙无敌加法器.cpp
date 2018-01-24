#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;

int main(){
	char rule[30],X[30],Y[30];
	scanf("%s %s %s",&rule,&X,&Y);
	int x=strlen(X)-1, y=strlen(Y)-1,cnt=strlen(rule)-1,carry(0);
	deque<int> ans;
	while(x>=0 || y>=0){
		int temp=rule[cnt]-'0';
		if(temp==0) temp=10;
		if(x>=0 && y>=0){
			ans.push_back((X[x]-'0'+Y[y]-'0'+carry)%temp);
			carry=(X[x]-'0'+Y[y]-'0'+carry)/temp;
			x--;
			y--;
			cnt--;
		}else if(x>=0){
			ans.push_back((X[x]-'0'+carry)%temp);
			carry=(X[x]-'0'+carry)/temp;
			x--;
			cnt--;
		}else if(y>=0){
			ans.push_back((Y[y]-'0'+carry)%temp);
			carry=(Y[y]-'0'+carry)/temp;
			y--;
			cnt--;	
		}else {
			break;
		}
	}
	if(carry!=0){
		int temp = rule[cnt]-'0';
		if(temp==0) temp=10;
		ans.push_back(carry%temp);
	}
	while(ans.size()!=0&&ans.back()==0){
		ans.pop_back();
	}
	if(!ans.size()) printf("0");
	else {
		while(ans.size()){
			printf("%d",ans.back());
			ans.pop_back();
		}
	}
	
}
