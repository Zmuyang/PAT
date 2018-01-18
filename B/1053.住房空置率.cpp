#include <iostream>
using namespace std;

int main(){
	double low,temp;
	int n,D,d,May(0),Must(0);
	cin >> n >> low >> D;
	for(int i=0;i<n;i++){
		cin >> d;
		int cnt(0);
		for(int j=0;j<d;j++){
			cin >> temp;
			if(temp<low) cnt++;
		}
		if(cnt>d/2){
			d>D ? Must++:May++;
		}
	}
	double may = (double)May/n*100;
	double must = (double)Must/n*100;
	printf("%.1f%% %.1f%%",may,must);
	return 0;
}
