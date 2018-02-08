#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;

bool vis[10010];
set<int> Node;
vector<vector<int>> G;
vector<int> temp;
int n,H(0); 

void DFS(int node,int h){
	if(h>H){
		temp.clear() ;
		temp.push_back(node);
		H=h; 
	}else if(h==H){
		temp.push_back(node); 
	}
	vis[node]=true;
	for(int i=0;i<G[node].size();i++){
		if(vis[G[node][i]]==false){
			DFS(G[node][i],h+1);
		}
	}
}

int main(){
	int a,b,cnt(0),s1(0);
	cin >> n;
	G.resize(n+1);
	for(int i=0;i<n-1;i++){
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a); 
	}
	
	for(int i=1;i<=n;i++){
		if(vis[i]==false){
			DFS(i,1);
			if(i==1){
				for(int j=0;j<temp.size();j++){
					Node.insert(temp[j]);
					if(j==0) s1=temp[j];
				}
			}
			cnt++;
		}
	}
	if(cnt>=2){
		printf("Error: %d components\n",cnt);
	}else{
		temp.clear();
		H=0;
		fill(vis,vis+10010,false);
		DFS(s1,1);
		for(int i=0;i<temp.size();i++){
			Node.insert(temp[i]);
		}
		for(auto it=Node.begin();it!=Node.end();it++){
			printf("%d\n",*it);
		}
	}
	return 0;
}
