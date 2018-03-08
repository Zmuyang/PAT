#include <iostream>
#include <vector>
using namespace std;

const int maxn=110;
vector<int> Node[maxn];
int hashTable[maxn];

void DFS(int index, int lev){
	hashTable[lev]++;
	for(int i=0;i<Node[index].size();i++){
		DFS(Node[index][i],lev+1);
	}
}

int main(){
	int n,m,parent,k,child;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		cin >> parent >> k;
		for(int j=0;j<k;j++){
			cin >> child;
			Node[parent].push_back(child);
		}
	}
	DFS(1,1);
	int maxLevel(-1),maxValue(0);
	for(int i=1;i<maxn;i++){
		if(hashTable[i]>maxValue){
			maxValue=hashTable[i];
			maxLevel=i;
		}
	}
	cout << maxValue << " " << maxLevel << endl;
	return 0;
}
