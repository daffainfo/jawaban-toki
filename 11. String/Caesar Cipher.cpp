#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	int k;
	ios_base::sync_with_stdio(false);
	cin.tie();
	cin>>s;
	cin>>k;
	for(int i=0; i<s.length(); i++)
		s[i] = ((s[i] - 'a' + k) % 26) + 'a';
	cout<<s<<'\n';
	return 0;
}