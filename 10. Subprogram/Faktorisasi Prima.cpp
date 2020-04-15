#include <iostream>

using namespace std;

bool cekprima(int a) {
	int i=2;
	bool prima=1;
	
	if(a==1) {
		prima = 0;
	} else if(a==2) {
		prima = 1;
	} else if((a>2) && ((a%2)==0)) {
		prima=0;
	} else {
		while((i*i)<=a) {
			if((a%i)==0) {
				prima = 0;
				break;
			}
			i++;
		}
	}
	
	return prima;
}

int main() {
	int n,i,pangkat,faktorke=1,m;
	
	cin>>n;
	i=2;
	while(i<=n) {
		pangkat=0;
		if(cekprima(i)) {
			while((n%i)==0){
				pangkat++;
				n/=i;
			}
		}
		
		if(faktorke==1) {
			if(pangkat==1)
				cout<<i;
			else if(pangkat>1)
				cout<<i<<"^"<<pangkat;
			else faktorke--;
		} else {
			if(pangkat==1)
				cout<<" x "<<i;
			else if(pangkat>1)
				cout<<" x "<<i<<"^"<<pangkat;
			else faktorke--;		
		}
		i++;
		faktorke++;
	}
	cout<<endl;
	
	return 0;
}
