#include <bits/stdc++.h>

using namespace std;

short movex[] = {0, 0, 1, -1};
short movey[] = {1, -1, 0, 0};
int nilai;
short bola[25][25];
short m, n;

void count(short x, short y, short ball) {
    if((bola[x][y] != ball) || (y < 0) || (x < 0) || (y >= 25) || (x >= 25)) return;
    else {
        nilai++;
        bola[x][y] = -1;
        for(int i=0; i < (sizeof(movex) / sizeof(short)); i++) {
            count(x + movex[i], y + movey[i], ball);
        }
    }
}

int main() {
    nilai = 0;
    cin>>m>>n;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++)
            cin>>bola[i][j];
    }
    short b, k;
    cin>>b>>k;
    count(b, k, bola[b][k]);
    cout<<((nilai - 1) * nilai)<<endl;
    return 0;
}