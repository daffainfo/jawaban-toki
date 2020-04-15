#include <bits/stdc++.h>
using namespace std;

int fpb(int a, int b) {
    if(a % b == 0) return b;
    else return fpb(b, a % b);
}

int main() {
	int n, gcd, a, b, kpk;
	cin>>n;
	for(int i=0; i<n; i++) {
		if(i==0) {
			cin>>a;
			continue;
		} else {
			cin>>b;
		}
		if(i==1) {
			if(a > b) gcd = fpb(a, b);
			else gcd = fpb(b, a);
			kpk = a * b / gcd;
		} else if(i > 1) {
			if(kpk > b) gcd = fpb(kpk, b);
			else gcd = fpb(b, kpk);
			kpk = kpk * b / gcd;
		}
	}
	cout<<kpk<<endl;
	return 0;
}