#include <bits/stdc++.h>
using namespace std;
typedef struct queuemember {
    int number = 0, banyak = 0;
}member;

int main() {
    vector <member> modqueue;
    int n, queue_size = 0;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    while(n--) {
        string cmd;
        cin>>cmd;
        if(cmd == "add") {
            member tmp;
            cin>>tmp.number>>tmp.banyak;
            queue_size += tmp.banyak;
            modqueue.push_back(tmp);
            cout<<queue_size<<'\n';
        } else if(cmd == "del") {
            int y;
            cin>>y;
            cout<<modqueue[0].number<<'\n';
            queue_size -= y;
            if(queue_size <= 0) {
                queue_size = 0;
                modqueue.clear();
            } else {
                while(y > 0) {
                    int elemenawal = modqueue[0].banyak;
                    modqueue[0].banyak -= y;
                    if(modqueue[0].banyak <= 0)
                        modqueue.erase(modqueue.begin());
                    y -= elemenawal;
                }
            }
        } else {
            vector <member> tmpqueue;
            for(int i=(modqueue.size() - 1); i >= 0; i--)
                tmpqueue.push_back(modqueue[i]);
            for(int i=0; i<modqueue.size(); i++)
                modqueue[i] = tmpqueue[i];
            tmpqueue.clear();
        }
    }
    return 0;
}
