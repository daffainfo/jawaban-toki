#include <bits/stdc++.h>
using namespace std;
typedef struct StackMember {
    int nomor, banyak;
} member;

int main() {
    vector <member> modstack;
    int n, isinya = 0;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    while(n--) {
        string command;
        cin>>command;
        if(command == "add") {
            member tmp;
            cin>>tmp.nomor>>tmp.banyak;
            isinya += tmp.banyak;
            cout<<isinya<<'\n';
            if(!modstack.empty() && modstack[modstack.size() - 1].nomor == tmp.nomor)
                modstack[modstack.size() - 1].banyak += tmp.banyak;
            else 
                modstack.push_back(tmp);
        } else if(command == "del") {
            int y;
            cin>>y;
            cout<<modstack[modstack.size() - 1].nomor<<'\n';
            isinya -= y;
            if(isinya < 0) {
                isinya = 0;
                modstack.clear();
            } else {
                while(y > 0) {
                    int elemenakhir = modstack[modstack.size() - 1].banyak;
                    modstack[modstack.size() - 1].banyak -= y;
                    if(modstack[modstack.size() - 1].banyak <= 0)
                        modstack.erase(modstack.end() - 1);
                    y -= elemenakhir;
                }
            }
        } else if(command == "dex") {
            int x;
            cin>>x;
            for(int i=0; i < modstack.size(); i++)
                modstack[i].nomor -= x;
        } else {
            int x;
            cin>>x;
            for(int i=0; i < modstack.size(); i++)
                modstack[i].nomor += x;
        }
    }
    return 0;
}