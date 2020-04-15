#include <bits/stdc++.h>

using namespace std;
int matrix[128][128];
int kodeindex;
string kode[16384];

bool homogen(int r, int c, int size) {
    for(int i = r; i < (r + size); i++) {
        for(int j = c; j < (c + size); j++) {
            if(matrix[r][c] != matrix[i][j])
                return false;
        }
    }
    return true;
}

bool ispowertwo(int n) {
    if(n == 2 || n == 4 || n == 8 || n == 16 || n == 32 || n == 64 || n == 128) return true;
    else return false;
}

void quadtree(int r, int c, int size, string kodenow) {
    if(homogen(r, c, size)) {
        if(matrix[r][c]) {
            kode[kodeindex] = "1" + kodenow;
            kodeindex++;
        }
    } else {
        quadtree(r, c, (size >> 1), kodenow + "0");
        quadtree(r, c + (size >> 1), (size >> 1), kodenow + "1");
        quadtree(r + (size >> 1), c, (size >> 1), kodenow + "2");
        quadtree(r + (size >> 1), c + (size >> 1), (size >> 1), kodenow + "3");
    }
}

int main() {
    kodeindex = 0;
    int r, c;
    cin>>r>>c;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin>>matrix[i][j];
        }
    }
    int rtemp = r, ctemp = c;
    if(!(ispowertwo(r) && ispowertwo(c))) {
        while(!ispowertwo(rtemp)) rtemp++;
        while(!ispowertwo(ctemp)) ctemp++;
    }
    for(int i=r; i<rtemp; i++) {
        for(int j=c; j<ctemp; j++) {
            matrix[i][j] = 0;
        }
    }
    r = ((rtemp > ctemp) ? rtemp : ctemp);
    c = r;
    string s;
    quadtree(0, 0, r, s);
    cout<<kodeindex<<'\n';
    for(int i = 0; i < kodeindex; i++)
        cout<<kode[i]<<'\n';
    return 0;
}