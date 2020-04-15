#include <bits/stdc++.h>

using namespace std;

short movex[] = {0, 0, 1, -1};
short movey[] = {1, -1, 0, 0};
int nilai, maks;
bool visited[25][25] = {0};
short bola[25][25];
short m, n;

void count(short x, short y, short ball) {
    if((bola[x][y] != ball) || visited[x][y] || (y < 0) || (x < 0) || (y >= 25) || (x >= 25)) return;
    else {
        nilai++;
        visited[x][y] = true;
        for(int i=0; i < (sizeof(movex) / sizeof(short)); i++) {
            count(x + movex[i], y + movey[i], ball);
        }
    }
}

int main() {
    maks = -1;
    cin>>m>>n;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++)
            cin>>bola[i][j];
    }
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(!visited[i][j]) {
                nilai = 0;
                count(i, j, bola[i][j]);
                if (nilai > maks) maks = nilai;
            }
        }
    }
    cout<<((maks - 1) * maks)<<endl;
    return 0;
}