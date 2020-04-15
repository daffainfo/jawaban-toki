#include <iostream>
#include <string>

using namespace std;

void camel(string *mem) {
	string s=*mem;
	int i;
	
	for(i=0; i<s.length(); i++) {
		if((s[i]>='A') && (s[i]<='Z')) {
			s[i]=s[i]-'A'+'a';
			s.insert(i,"_");
		}
	}
	*mem=s;
}

void snake(string *mem) {
	int ada=0;
	int dimana[255];
	string s=*mem;
	string und="_";
	int panjang=s.length();
	int temudi=s.find(und);
	
	while((temudi>=0) && (temudi<panjang)) {
		dimana[ada]=temudi;
		ada++;
		s.erase(temudi,1);
		temudi=s.find(und);
		panjang=s.length();
	}
	
	for(int i=0; i<ada;i++) {
		if(!(dimana[i]>=s.length())) {
			s[dimana[i]]-=32;
		}
	}
	
	*mem=s;
}

int main() {
	string s;
	string * mem;
	mem=&s;
	cin>>s;
	
	if((s.find("_")>=0) && ((s.find("_")<s.length())))
		snake(mem);
	else camel(mem);
	
	cout<<s<<endl;
	return 0;
}
