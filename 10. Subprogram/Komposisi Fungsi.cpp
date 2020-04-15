#include <iostream>

using namespace std;

int abs(int mutlak){
	if(mutlak>=0) {
		return mutlak;
	} else {
		mutlak= mutlak * (-1);
		return mutlak;
	}
}

int fungsi(int a, int b, int k, int x) {
	int hasil;
	if(k>1) {
		k--;
		hasil=abs((a*x)+b);
		fungsi(a,b,k,hasil);
	} else if(k==1) {
		hasil=abs((a*x)+b);
		return hasil;
	}
}

int main() {
	int a,b,k,x;
	
	cin>>a>>b>>k>>x;
	
	cout<<fungsi(a,b,k,x)<<endl;
	
	return 0;
}
