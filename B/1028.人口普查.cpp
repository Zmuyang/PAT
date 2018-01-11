#include <iostream>
#include <cstdio>

using namespace std;

struct Infor{
	string ID;
	int Y;
	int M;
	int D;
}MAX,MIN,L,R,temp;

bool S_cmp(struct Infor a,struct Infor b);
bool L_cmp(struct Infor a,struct Infor b);
void initial();

int main(){
	initial();
	int N,n(0);
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> temp.ID;
		scanf("%d/%d/%d",&temp.Y,&temp.M,&temp.D);
		if(S_cmp(temp,L)&&L_cmp(temp,R)){
			if(S_cmp(temp,MAX)){
				MAX = temp;
			}
			if(L_cmp(temp,MIN)){
				MIN = temp;
			}
			n++;
		}
	}
	if(n==0){
		cout << '0'<< endl;
	}else{
		cout << n << " " << MAX.ID << " " << MIN.ID << endl;
	}
	
	return 0;
}

void initial(){
	MAX.Y = L.Y = 2014;
	MIN.Y = R.Y = 1814 ;
	MAX.M = L.M = MIN.M = R.M =9;
	MAX.D = MIN.D = L.D = R.D = 6;
}
bool S_cmp(struct Infor a,struct Infor b){
	if(a.Y!=b.Y){
		return a.Y <= b.Y;
	}else if(a.M!=b.M){
		return a.M <= b.M;
	}else{
		return a.D <= b.D;
	}
}
bool L_cmp(struct Infor a,struct Infor b){
	if(a.Y!=b.Y){
		return a.Y >= b.Y;
	}else if(a.M!=b.M){
		return a.M >= b.M;
	}else{
		return a.D >= b.D;
	}
}
