#include <bits/stdc++.h>
#define sizebool(x) (sizeof(x)/sizeof(bool))
#define sizeshort(x) (sizeof(x)/sizeof(short))
#define set0(x, z) memset(x, 0, z)
using namespace std;

short movex[] = {0, 0, 1, -1}, movey[] = {1, -1, 0, 0}, m, n;
int nilai, maks = -1;

void count(short x, short y, short ball, short bola[25][25], bool visited[25][25], bool runtuhkan) {
    if((bola[x][y] != ball) || ((runtuhkan) ? false : visited[x][y]) || (y < 0) || (x < 0) || (y >= 25) || (x >= 25)) return;
    else {
        nilai++;
        if(runtuhkan) bola[x][y] = -1;
        else visited[x][y] = true;
        for(int i=0; i < sizeshort(movex); i++) {
            count(x + movex[i], y + movey[i], ball, bola, visited, runtuhkan);
        }
    }
}

void runtuh(short bola[25][25]) {
    for(int i=0; i<n; i++) {
        bool ada = true;
        while(ada) {
            ada = false;
            for(int j=0; j<(m - 1); j++) {
                if(bola[j][i] != -1 && bola[j+1][i] == -1) {
                    ada = true;
                    bola[j][i] ^= bola[j+1][i];
                    bola[j+1][i] ^= bola[j][i];
                    bola[j][i] ^= bola[j+1][i];
                }
            }
        }
    }
}

void printmatrix(short bola[25][25]) {
    for(int a=0; a<m; a++) {
        for(int b=0; b<n; b++) {
            if(bola[a][b] != -1) cout<<bola[a][b];
            else cout<<'.';
            if(b < n - 1) cout<<' ';
            else cout<<'\n';
        }
    }
}

int main() {
    short bola[25][25];
    bool visited[25][25] = {0};
    int x, y;
    cin>>m>>n;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++)
            cin>>bola[i][j];
    }
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(!visited[i][j]) {
                nilai = 0;
                count(i, j, bola[i][j], bola, visited, false);
                if(nilai > maks) {
                    maks = nilai;
                    x = i;
                    y = j;
                }
            }
        }
    }
    set0(visited, sizebool(visited));
    count(x, y, bola[x][y], bola, visited, true);
    runtuh(bola);
    printmatrix(bola);
    return 0;
}