#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int Cmp(struct St a, struct St b);

struct St{
	int ID;
	int De,Cai;
};

int main(){
	int n,L,H;
	cin >> n >> L >> H ;
	int cnt = n;
	St temp;
	vector<St> a,b,c,d;
	for(int i=0;i<n;i++){
		cin >> temp.ID >> temp.De >> temp.Cai;
		if(temp.De<L || temp.Cai<L){
			cnt--;
			continue;
		}
		if(temp.De>=H && temp.Cai >=H){
			a.push_back(temp);
		}else if(temp.De>=H && temp.Cai<H){
			b.push_back(temp);
		}else if(temp.De>=temp.Cai&& temp.De<H && temp.Cai<H){     //注意大于等于范围 
			c.push_back(temp);
		}else{
			d.push_back(temp);
		}
	}
	sort(a.begin(),a.end(),Cmp);
	sort(b.begin(),b.end(),Cmp);
	sort(c.begin(),c.end(),Cmp);
	sort(d.begin(),d.end(),Cmp);
	cout << cnt << '\n';
	
	vector<St> :: iterator itr;
	for(itr=a.begin();itr!=a.end();itr++){
		printf("%d %d %d\n",itr->ID,itr->De,itr->Cai);
	}
	for(itr=b.begin();itr!=b.end();itr++){
		printf("%d %d %d\n",itr->ID,itr->De,itr->Cai);
	}
	for(itr=c.begin();itr!=c.end();itr++){
		printf("%d %d %d\n",itr->ID,itr->De,itr->Cai);
	}
	for(itr=d.begin();itr!=d.end();itr++){
		printf("%d %d %d\n",itr->ID,itr->De,itr->Cai);
	}
	return 0;
}

int Cmp(struct St a,struct St b){
	if((a.De+a.Cai)!=(b.De+b.Cai)){
		return a.De+a.Cai > b.De+b.Cai;
	}else if(a.De!=b.De){
		return a.De > b.De;
	}else{
		return a.ID<b.ID;
	}
}
