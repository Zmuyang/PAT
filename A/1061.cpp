#include <iostream>
#include <vector>
using namespace std;

int main(){
	char week[7][5]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
	string s1,s2,s3,s4;
	cin >> s1 >> s2 >> s3 >> s4;
	int len1=min(s1.size(),s2.size());
	int len2=min(s3.size(),s4.size());
	int cnt(0),D,H,M;
	for(int i=0;i<len1;i++){
		if(cnt==1){
			if(s1[i]==s2[i]&&s1[i]>='A'&&s1[i]<='N'&&s2[i]>='A'&&s2[i]<='N'){
				H=s1[i]-'A'+10;
				break;
			}else if(s1[i]==s2[i]&&s1[i]>='0'&&s1[i]<='9'&&s2[i]>='0'&&s2[i]<='9'){
				H=s1[i]-'0';
				break;
			}
		}
		if(s1[i]==s2[i]&&s1[i]>='A'&&s1[i]<='G'&&s2[i]>='A'&&s2[i]<='G'){
			D=s1[i]-'A'+1;
			cnt=1;
		}
	}
	for(int i=0;i<len2;i++){
		if(s3[i]==s4[i]&&(s3[i]>='A'||s3[i]>='a')&&(s3[i]<='Z'||s3[i]<='z')&&(s4[i]>='A'||s4[i]>='a')&&(s4[i]<='Z'||s4[i]<='z')){
			M=i;
		}
	}
	printf("%s %02d:%02d",week[D-1],H,M);
	return 0;
} 
