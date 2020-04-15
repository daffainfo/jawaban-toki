#include <bits/stdc++.h>

using namespace std;
int matrix[128][128];
int r, c, n;
string code[128*128];

bool ispowertwo(int n) {
    if(n == 2 || n == 4 || n == 8 || n == 16 || n == 32 || n == 64 || n == 128) return true;
    else return false;
}

void changeto1(int r, int c, int size, string kode) {
    if(kode.length() == 0) {
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++)
                matrix[i][j] = 1;
        }
        return;
    }
    if(kode.length() == 1) {
        if(kode == "0") {
            for(int i = r; i < (r + (size >> 1)); i++) {
                for(int j = c; j < (c + (size >> 1)); j++)
                    matrix[i][j] = 1;
            }
        } else if(kode == "1") {
            for(int i = r; i < (r + (size >> 1)); i++) {
                for(int j = c + (size >> 1); j < (c + size); j++)
                    matrix[i][j] = 1;
            }
        } else if(kode == "2") {
            for(int i = r + (size >> 1); i < (r + size); i++) {
                for(int j = c; j < (c + (size >> 1)); j++)
                    matrix[i][j] = 1;
            }
        } else {
            for(int i = r + (size >> 1); i < (r + size); i++) {
                for(int j = c + (size >> 1); j < (c + size); j++)
                    matrix[i][j] = 1;
            }
        }
    } else {
        char pos = kode[0];
        kode.erase(kode.begin());
        if(pos == '0') changeto1(r, c, (size >> 1), kode);
        else if(pos == '1') changeto1(r, c + (size >> 1), (size >> 1), kode);
        else if(pos == '2') changeto1(r + (size >> 1), c, (size >> 1), kode);
        else changeto1(r + (size >> 1), c + (size >> 1), (size >> 1), kode);
    }
}

int main() {
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>code[i];
    cin>>r>>c;
    int rtemp = r, ctemp = c;
    if(!(ispowertwo(r) && ispowertwo(c))) {
        while(!ispowertwo(rtemp)) rtemp++;
        while(!ispowertwo(ctemp)) ctemp++;
    }
    rtemp = (ctemp > rtemp) ? ctemp : rtemp;
    ctemp = rtemp;
    for(int i = 0; i < rtemp; i++) {
        for(int j = 0; j < ctemp; j++)
            matrix[i][j] = 0;
    }
    if(n != 0) {
        for(int i = 0; i < n; i++) {
            code[i].erase(code[i].begin());
            changeto1(0, 0, rtemp, code[i]);
        }
    }
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout<<matrix[i][j];
            if(j == c - 1) cout<<'\n';
            else cout<<" ";
        }
    }
    return 0;
}