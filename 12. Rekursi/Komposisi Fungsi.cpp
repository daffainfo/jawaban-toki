#include <iostream>

using namespace std;

int a,b,x;

int abs(int a) {
	if (a>=0)
		return a;
	else return (a*(-1));
}

int fungsi(int k){
	if(k==1)
		return abs((a*x+b));
	else return abs((a*fungsi(k-1)+b));
}

int main() {
	int k;
	cin>>a>>b>>k>>x;
	
	cout<<fungsi(k)<<endl;
	return 0;
}
