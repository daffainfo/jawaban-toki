#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    vector <int> snq;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    while(n--) {
        string cmd;
        cin>>cmd;
        if(cmd == "push_back") {
            int tmp;
            cin>>tmp;
            snq.push_back(tmp);
        } else if(cmd == "push_front") {
            int tmp;
            cin>>tmp;
            if(snq.empty()) snq.push_back(tmp);
            else snq.emplace(snq.begin(), tmp);
        } else if(cmd == "pop_front")
            snq.erase(snq.begin());
        else
            snq.pop_back();
    }
    for(int i=0; i < snq.size(); i++)
        cout<<snq[i]<<'\n';
    return 0;
}