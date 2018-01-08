#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	char Day[7][4] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
	int flag(0) , H(0) , M(0) ,cnt(0);
	char L,DAY='A';
	
	string A,B,C,D;
	cin >> A >> B >> C >> D;
	int MinF = A.length() < B.length() ? A.length() : B.length();
	int MinT = C.length() < D.length() ? C.length() : D.length();
	
	for(int i=0;i<MinF;i++){
		if(A[i] == B[i] && flag == 0 && A[i] >= 'A' && A[i]<= 'G'){
			L=A[i];
			flag = 1;
			continue;
		}
		
		if(A[i]==B[i] && A[i] - '0' >= 0 && A[i]-'0'<=9 && flag==1){
			H = A[i]-'0';
			break;
		}else if(A[i]==B[i]&&A[i]>='A'&&A[i]<='N'&&flag==1){
			H = A[i] - 'A' +10; //зЂвт 
			break;
		}
	}
	
	cnt = L- 'A';
	
	for(int i=0;i<MinT;i++){
		if(C[i]==D[i]&& ( (C[i]>='A'&&C[i]<='Z') || (C[i]>='a' && C[i]<='z') ) ){ //зЂвт 
			M=i;
			break;
		}
	}
	cout << Day[cnt];
	printf(" %02d:%02d",H,M);
	return 0;
} 
