#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int address , L , R, temp , cnt(0);
	cin >> address >> L >> R;
	int data[100005],next[100005],list[100005];
	for(int i=0;i<L;i++){
		cin >> temp;
		cin >> data[temp] >> next[temp];
	}
	
	while(address!=-1){
		list[cnt++] = address;
		address = next[address];
	}
	for(int i=0;i<(cnt-cnt%R);i+=R){
		reverse(begin(list)+i,begin(list)+i+R); // зЂвт 
	}
	for(int i=0;i<cnt-1;i++){
		printf("%05d %d %05d\n",list[i],data[list[i]],list[i+1]);
	} 
	printf("%05d %d -1",list[cnt-1],data[list[cnt-1]]);
	return 0;
} 
