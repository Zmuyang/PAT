#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

struct Register{
	string ID;
	int H1,M1,S1;
	int H2,M2,S2;
}Res[100],UNloc,Loc;

int CMP_u(struct Register a,struct Register b);
int CMP_l(struct Register a,struct Register b);

int main(){
	int M;
	cin >> M;
	for(int i=0;i<M;i++){
		cin >> Res[i].ID;
		char U[20],L[20];   // sscanf只识别char类型字符串 
		cin >> U >> L;
		sscanf(U,"%d:%d:%d",&Res[i].H1,&Res[i].M1,&Res[i].S1);
		sscanf(L,"%d:%d:%d",&Res[i].H2,&Res[i].M2,&Res[i].S2);
	}
	sort(Res,Res+M,CMP_u);
	UNloc=Res[0];
	sort(Res,Res+M,CMP_l);
	Loc=Res[0];
	cout << UNloc.ID << " " << Loc.ID << endl;
	return 0;
}


int CMP_u(struct Register a,struct Register b){
	if(a.H1!=b.H1) return a.H1<b.H1;
	else if(a.M1!=b.M1) return a.M1<b.M1;
	else return a.S1<b.S1;
}
int CMP_l(struct Register a,struct Register b){
	if(a.H2!=b.H2) return a.H2>b.H2;
	else if(a.M2!=b.M2) return a.M2>b.M2;
	else return a.S2>b.S2;
}
