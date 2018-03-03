#include <cstdio>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int maxn(100000);
bool exist[maxn];
struct Node{
	int address;
	int key;
	int next;
	int num;
}node[maxn];

int cmp(Node a, Node b){
	return a.num<b.num;
}

int main(){
	int begin,cnt1(0),cnt2(0),x,n;
	scanf("%d%d",&begin,&n);
	for(int i=0;i<maxn;i++){
		node[i].num=maxn*2;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		scanf("%d%d",&node[x].key,&node[x].next);
		node[x].address=x;
	}
	for(int i=begin;i!=-1;i=node[i].next){
		if(exist[abs(node[i].key)]==false){
			exist[abs(node[i].key)]=true;
			node[i].num=cnt1;
			cnt1++;
		}else{
			node[i].num=maxn+cnt2;
			cnt2++;
		}
	}
	sort(node,node+maxn,cmp);
	int cnt=cnt1+cnt2;
	for(int i=0;i<cnt;i++){
		if(i!=cnt1-1&&i!=cnt-1){
			printf("%05d %d %05d\n",node[i].address,node[i].key,node[i+1].address);
		}else{
			printf("%05d %d -1\n",node[i].address,node[i].key);
		}
	}
	return 0;
}
