#include <iostream>

using namespace std;

unsigned int reverse(unsigned int x) {
    unsigned int temp = x;
    unsigned int ret  = 0;

    while (temp > 0) {
        ret  = (ret * 10) + (temp % 10);
        temp = temp / 10;
    }

    return ret;
}

int main() {
	unsigned int a,b,c;
	
	cin>>a>>b;
	
	c= reverse(a) + reverse(b);
	c= reverse(c);
	
	cout<<c<<endl;
	
	return 0;
}
