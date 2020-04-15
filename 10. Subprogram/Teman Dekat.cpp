#include <iostream>

using namespace std;

int abs(int a) {
	if (a>=0)
		return a;
	else return (a*(-1));
}

int pow(int a, int b) {
	int n=a;
	while (b>1) {
		n*=a;
		b--;
 }
	return n;
}

int kedekatan(int xj, int xi, int yj, int yi, int d) {
	return (pow(abs(xj-xi), d)+pow(abs(yj-yi), d));
}

int main() {
	int n,d,i,j,hasil,terbesar=0,terkecil=0;
	int param[1001][3];
	cin>>n>>d;
	
	for(i=0; i<n;i++) {
		for(j=0; j<2; j++) {
			cin>>param[i][j];
		}
	}
	
	for(i=0; i<n;i++) {
		for(j=i+1; j<n; j++) {
			hasil=kedekatan(param[j][0],param[i][0],param[j][1],param[i][1], d);
			if((terkecil==0) && (terbesar==0)){
				terbesar=hasil;
				terkecil=hasil;
			}
			if(hasil>terbesar)
				terbesar=hasil;
			if(hasil<terkecil)
				terkecil=hasil;
		}
	}
	cout<<terkecil<<" "<<terbesar<<endl;
	return 0;
}
