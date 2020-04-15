#include <iostream>
#include <string>

using namespace std;

int main() {
	string a,b;
	
	cin>>a>>b;
	while((a.find(b)<a.length()) && (a.find(b)>=0)) {
		a.erase(a.find(b), b.length());
	}
	cout<<a<<endl;
	return 0;
}
