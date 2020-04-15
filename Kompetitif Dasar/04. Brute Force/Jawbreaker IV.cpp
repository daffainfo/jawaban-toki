#include <bits/stdc++.h>
using namespace std;
short movex[] = {0, 0, 1, -1}, movey[] = {1, -1, 0, 0}, m, n;
int nilai;

void count(short x, short y, short ball, short bola[25][25], bool visited[25][25], bool marked) {
    if((bola[x][y] != ball) || (visited[x][y])|| (y < 0) || (x < 0) || (y >= n) || (x >= m)) return;
    else {
        nilai++;
        if(marked) bola[x][y] = -1;
        visited[x][y] = true;
        for(int i=0; i < 4; i++) {
            count(x + movex[i], y + movey[i], ball, bola, visited, marked);
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

void copyball(short dest[25][25], short source[25][25]) {
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            dest[i][j] = source[i][j];
        }
    }
}

int step2(short bola[25][25]) {
    bool visited[25][25] = {0};
    short ball[25][25];
    copyball(ball, bola);
    int max = 0;
    for(int i=0; i<m; i++) {
        for(int j=0; j<m; j++) {
            if(visited[i][j] || ball[i][j] == -1) continue;
            nilai = 0;
            count(i, j, ball[i][j], ball, visited, false);
            if(nilai == 1) continue;
            max = (nilai > max) ? nilai : max;
        }
    }
    return max;
}

int main() {
    bool visited[25][25] = {0};
    short bola[25][25] = {0};
    int maks = 0, x, y;
    cin>>m>>n;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++)
            cin>>bola[i][j];
    }
    short ball[25][25];
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(visited[i][j]) continue;
            nilai = 0;
            copyball(ball, bola);
            count(i, j, ball[i][j], ball, visited, true);
            if(nilai == 1) continue;
            runtuh(ball);
            int tmp = nilai * (nilai - 1);
            int nilai2 = step2(ball);
            tmp += (nilai2 * (nilai2 - 1));
            maks = (tmp > maks) ? tmp : maks;
        }
    }
    cout<<maks<<endl;
    return 0;
}