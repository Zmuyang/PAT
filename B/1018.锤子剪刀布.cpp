#include <iostream>

using namespace std;
bool WF(char a,char b);

int main(){
	int jia_C(0),jia_J(0),jia_B(0);
	int yi_C(0),yi_J(0),yi_B(0);
	int equal(0);
	char J,Y;
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> J >> Y;
		if(J=='C'&&Y=='J'){
			jia_C++;
			continue;
		}
		if(J=='J'&&Y=='B'){
			jia_J++;
			continue;
		}
		if(J=='B'&&Y=='C'){
			jia_B++;
			continue;
		}
		if(J=='C'&&Y=='B'){
			yi_B++;
			continue;
		}
		if(J=='B'&&Y=='J'){
			yi_J++;
			continue;
		}
		if(J=='J'&&Y=='C'){
			yi_C++;
			continue;
		}
		if((J=='C'&&Y=='C') || (J=='B'&&Y=='B') || (J=='J'||Y=='J')){
			equal++;
			continue;
		}
	}
	cout << jia_C + jia_J + jia_B << " " << equal <<" "<< yi_C + yi_B + yi_J << endl;
	cout << yi_C + yi_B + yi_J << " " << equal <<" "<< jia_C + jia_J + jia_B << endl;
	if(jia_B>=jia_C&&jia_B>=jia_J){
		cout << 'B' << " " ;
	}else if( jia_C>=jia_J&&jia_C>jia_B ){
		cout << 'C' << " ";
	}else if(jia_J>jia_C&&jia_J>jia_B ){
		cout << 'J' << " ";
	}
	
	if(yi_B>=yi_C&&yi_B>=yi_J){
		cout << 'B';
	}else if( yi_C>=yi_J&&yi_C>yi_B ){
		cout << 'C';
	}else if(yi_J>yi_C&&yi_J>yi_B ){
		cout << 'J';
	}
	return 0;
}

