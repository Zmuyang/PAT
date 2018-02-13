#include <iostream>
#include <map>
using namespace std;

map<string,int> s_i;
map<int,string> i_s;
map<string,int> gang;
int number(1),k;
int G[2010][2010],weight[2010];
bool vis[2010];

int stoifunc(string s){
	if(s_i[s]==0){
		s_i[s]=number;
		i_s[number]=s;
		return number++;
	}else{
		return s_i[s];
	}
}

void DFS(int u,int& head,int& numMember,int& totalweight){
	vis[u]=true;
	numMember++;
	if(weight[u]>weight[head]){
		head=u;
	}
	for(int v=1;v<number;v++){
		if(G[u][v]>0){
			totalweight+=G[u][v];
			G[u][v]=G[v][u]=0;
			if(vis[v]==false){
				DFS(v,head,numMember,totalweight);
			}
		}
	}
}
void DFSTrave(){
	for(int i=1;i<number;i++){
		if(vis[i]==false){
			int head=i,numMember=0,totalweight=0;
			DFS(i,head,numMember,totalweight);
			if(numMember>2 && totalweight>k){
				gang[i_s[head]] = numMember;
			}
		}
	}
}
int main(){
	int n,w;
	cin >> n >> k;
	string s1,s2;
	for(int i=0;i<n;i++){
		cin >> s1 >> s2 >> w;
		int id1=stoifunc(s1);
		int id2=stoifunc(s2);
		weight[id1]+=w;
		weight[id2]+=w;
		G[id1][id2]+=w;
		G[id2][id1]+=w;
	}
	DFSTrave();
	cout << gang.size() << endl;
	for(map<string,int>::iterator it=gang.begin();it!=gang.end();it++){
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}
