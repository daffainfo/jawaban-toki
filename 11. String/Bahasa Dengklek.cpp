#include <iostream>
#include <cstring>

using namespace std;

int main() {
	char s[101];
	int i;
	
	cin>>s;
	for(i=0; i<strlen(s); i++) {
		if((s[i]>='A') && (s[i]<'a'))
			s[i]= s[i]-'A'+'a';
		 else s[i]= s[i]-'a'+'A';
	}
	
	cout<<s<<endl;
	
	return 0;
}
