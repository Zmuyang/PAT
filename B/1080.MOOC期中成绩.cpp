#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct node{
	string name;
	long long OL,mid,end,G;
};

bool cmp(struct node a,struct node b){
	return a.G!=b.G ? a.G>b.G:a.name<b.name;
}

map<string,int> idx;

int main(){
	int O,M,E,score,cnt(1);
	cin >> O >> M >> E;
	vector<node> v,stu;
	string s;
	for(int i=0;i<O;i++){
		cin >> s >> score;
		if(score>=200){
			v.push_back(node{s,score,-1,-1,0});
			idx[s]=cnt++;
		}
	}
	for(int i=0;i<M;i++){
		cin >> s >> score;
		if(idx[s]!=0){
			v[idx[s]-1].mid = score;
		}
	}
	for(int i=0;i<E;i++){
		cin >> s >> score;
		if(idx[s]!=0){
			int temp = idx[s]-1;
			v[temp].end = v[temp].G = score;
			if(v[temp].mid>v[temp].end) {
				v[temp].G = int(v[temp].mid*0.4+v[temp].end*0.6+0.5);
			}
		}
	}
	for(int i=0;i<v.size();i++){
		if(v[i].G>=60){
			stu.push_back(v[i]);
		}
	}
	sort(stu.begin(),stu.end(),cmp);
	for(int i=0;i<stu.size();i++){
		cout << stu[i].name << " " << stu[i].OL << " " << stu[i].mid << " " << stu[i].end << " " << stu[i].G << endl;
	}
	return 0; 
}
