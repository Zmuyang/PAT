#include <iostream>
#include <queue>
using namespace std;

struct Node{
	int x,y,z;
}node;

int n,m,slice,T;
int pixel[1290][130][61];
bool inq[1290][130][61]={false};
int X[6]={0,0,0,0,1,-1};
int Y[6]={0,0,1,-1,0,0};
int Z[6]={1,-1,0,0,0,0};


bool Judge(int x,int y,int z){
	if(x<0||x>=n||y<0||y>=m||z>=slice||z<0){
		return false;
	}
	if(pixel[x][y][z]==0||inq[x][y][z]==true){
		return false;
	}
	return true;
}

int BFS(int x,int y,int z){
	int tot(0);
	queue<Node> q;
	node.x=x;
	node.y=y;
	node.z=z;
	q.push(node);
	inq[x][y][z]=true;
	while(!q.empty()){
		Node top=q.front();
		q.pop();
		tot++;
		for(int i=0;i<6;i++){
			int newX=top.x+X[i];
			int newY=top.y+Y[i];
			int newZ=top.z+Z[i];
			if(Judge(newX,newY,newZ)){
				node.x=newX;
				node.y=newY;
				node.z=newZ;
				q.push(node);
				inq[newX][newY][newZ]=true;
			}
		}
	}
	if(tot>=T){
		return tot;
	}else return 0;
}

int main(){
	cin >> n >> m >> slice >> T;
	for(int z=0;z<slice;z++){
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				scanf("%d",&pixel[x][y][z]);
			}
		}
	}
	int ans(0);
	for(int z=0;z<slice;z++){
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				if(pixel[x][y][z]==1&&inq[x][y][z]==false){
					ans+=BFS(x,y,z);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
