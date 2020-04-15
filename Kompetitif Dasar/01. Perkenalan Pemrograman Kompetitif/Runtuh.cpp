#include <bits/stdc++.h>
using namespace std;

string papan[20];
string satu, nol;
int r, c;

bool masihruntuh() {
    for(int i=0; i<r; i++) {
        if(satu == papan[i]) return true;
    }
    return false;
}

void runtuhkan() {
    short lastsatu = 0;
    for(int i=0; i<r; i++) {
        if(papan[i] == satu) {
            papan[i] = nol;
            lastsatu = i;
        }
    }
    for(int i=0; i<c; i++) {
        short berapasatu = 0, lowestsatu = r;
        for(int j=0; j<lastsatu; j++) {
            if(papan[j][i] == '1') {
                berapasatu++;
                papan[j][i] = '0';
            }
        }
        for(int j=(lastsatu+1); j < r; j++) {
            if(papan[j][i] == '1') {
                lowestsatu = j;
                break;
            }
        }
        for(int j=(lowestsatu-1); ((j>=0) && (berapasatu > 0)); j--) {
            berapasatu--;
            papan[j][i] = '1';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>r>>c;
    for(int i=0; i<r; i++)
        cin>>papan[i];
    for(int i=0; i<c; i++) {
        satu += "1";
        nol += "0";
    }
    while(masihruntuh())
        runtuhkan();
    for(int i=0; i<r; i++)
        cout<<papan[i]<<endl;
    return 0;
}