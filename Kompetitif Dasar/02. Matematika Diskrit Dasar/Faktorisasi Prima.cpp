#include <bits/stdc++.h>

using namespace std;

bool isprime(int n) {
	for(int i = 2; i * i <= n; i++) {
		if(n % i == 0) return false;
	}
	return true;
}

int main() {
	int n, nasli, i = 2;
	cin>>n;
	nasli = n;
	while(n > 1) {
		while(!isprime(i)) {
			i++;
		}
		if((n != nasli) && (n % i == 0)) cout<<" x ";
		int div = 0;
		while(n % i == 0) {
			div++;
			n /= i;
		}
		if(div == 1) cout<<i;
		else if(div > 1) cout<<i<<'^'<<div;
		i++;
	}
	cout<<endl;
	return 0;
}