#include <iostream>
using namespace std;

bool HashTable[10010];

bool isprime(int x){
	if(x==1) return false;
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			return false;
		}
	}
	return true;
} 

int func(int x){
	while(isprime(x)==false){
		x++;
	}
	return x;
}

int main(){
	int Tsize,n,key;
	cin >> Tsize >> n;
	int size=func(Tsize);
	for(int i=0;i<n;i++){
		cin >> key;
		int index = key%size;
		if(HashTable[index]==false){
			HashTable[index]=true;
			if(i!=0) cout << " ";
			cout << index;
		}else{
			int flag(0);
			for(int step=1;step<size;step++){
				index=(key+step*step)%size;
				if(HashTable[index]==false){
					HashTable[index]=true;
					flag=1;
					if(i!=0) cout << " ";
					cout << index;
					break;
				}
			}
			if(flag==0){
				if(i!=0) cout << " ";
				cout << '-';
			}
		}
	}
	return 0;
}
