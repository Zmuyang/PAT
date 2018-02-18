#include <cstdio>
#include <cstring>

char a[10005],b[10005];
bool HashTable[128];

int main(){
	gets(a);
	gets(b);
	int LA=strlen(a);
	int LB=strlen(b);
	for(int i=0;i<LB;i++){
		HashTable[b[i]]=true;
	}
	for(int i=0;i<LA;i++){
		if(HashTable[a[i]]==false){
			printf("%c",a[i]);
		}
	}
	return 0;
}
