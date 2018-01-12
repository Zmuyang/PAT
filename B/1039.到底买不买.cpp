#include <iostream>
#include <string>

using namespace std;

int main(){
	string B,N;
	cin >> B;
	cin >> N;
	int n=N.length();
	for(int i=0;i<N.length();i++){
		for(int j=0;j<B.length();j++){
			if(N[i]==B[j]){
				B.erase(j,1);  //É¾³ýÖ¸¶¨Î»ÖÃ×Ö·û 
				n--;
				break;
			}
		}
	}
	if(n==0){
		cout << "Yes " << B.length() ;
	}else{
		cout << "No " << n;
	}
	return 0;
}
