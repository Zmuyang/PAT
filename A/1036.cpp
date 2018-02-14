#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct node{
	string ID;
	string name;
	int grade;
};

int main(){
	int N;
	cin >> N;
	vector<node> st(N);
	map<char,node> result;
	result['F'].grade = -1;
	result['M'].grade = 101;
	for(int i=0;i<N;i++){
		char gender;
		cin >> st[i].name >> gender >> st[i].ID >> st[i].grade;
		if(gender=='F'){
			if(st[i].grade > result['F'].grade){
				result['F'] = st[i];
			}
		}else{
			if(st[i].grade<result['M'].grade){
				result['M'] = st[i];
			}
		}
	}
	if(result['F'].grade==-1){
		cout << "Absent" << '\n' << result['M'].name << " " << result['M'].ID << '\n' << "NA";
		return 0;
	}if(result['M'].grade==101){
		cout << result['F'].name << " " << result['F'].ID << '\n' << "Absent" << '\n' << "NA";
		return 0;
	}
	cout << result['F'].name << " " << result['F'].ID << '\n' << result['M'].name << " " << result['M'].ID << '\n' << result['F'].grade - result['M'].grade;
	return 0;
}
