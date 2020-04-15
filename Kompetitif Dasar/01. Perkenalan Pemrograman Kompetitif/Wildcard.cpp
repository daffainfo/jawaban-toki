#include <bits/stdc++.h>

using namespace std;

int main() {
    string a;
    int n;
    cin>>a;
    cin>>n;
    if(a == "*") {
        while (n--) {
            string tmp;
            cin>>tmp;
            cout<<tmp<<endl;
        }
    } else if(a[0] == '*') {
        a.erase(0, 1);
        while(n--) {
            string tmp;
            cin>>tmp;
            if(tmp.find(a, (tmp.length() - a.length())) != string::npos) cout<<tmp<<endl;
        }
    } else if(a[a.length()-1] == '*') {
        a.erase(a.length()-1, 1);
        while(n--) {
            string tmp;
            cin>>tmp;
            if(tmp.find(a) == 0) cout<<tmp<<endl;
        }
    } else {
        string awal = a, akhir = a;
        int star = a.find("*");
        awal.erase(star);
        akhir.erase(0, star + 1);
        while(n--) {
            string tmp;
            cin>>tmp;
            if(tmp.length() >= (awal.length() + akhir.length())) {
                if((tmp.find(awal) == 0) && (tmp.find(akhir, (tmp.length() - akhir.length())) != string::npos))
                    cout<<tmp<<endl;
            }
        }
    }
    return 0;
}