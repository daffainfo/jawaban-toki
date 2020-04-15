#include <iostream>

using namespace std;

string biner(int N) {
    if (N==1)
        return "1";
    else if (N % 2 == 1)
        return biner(N/2) + "1";
    else
        return biner(N/2) + "0";
}

int main() {
	int N;
	cin>>N;
	
	cout<<biner(N)<<endl;
	return 0;
}
