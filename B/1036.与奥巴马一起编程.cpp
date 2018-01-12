#include <iostream>

using namespace std;

int main(){
	int row(0),rank;
	char a;
	cin >> rank >> a;
	row = (rank+1)/2;
	for(int i=0;i<rank;i++) cout << a;
	cout << endl;
	for(int i=0;i<row-2;i++){
		cout << a;
		for(int j=0;j<rank-2;j++) cout << " ";
		cout << a << endl;
	} 

	for(int i=0;i<rank;i++) cout << a;
	return 0;
}
