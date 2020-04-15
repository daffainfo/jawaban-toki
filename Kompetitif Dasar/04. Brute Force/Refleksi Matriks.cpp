#include <iostream>

using namespace std;

unsigned short matrixa[75][75],matrixb[75][75], xa,ya,xb,yb;

bool identik() {
    if(xa!=xb || ya!=yb) return 0;
    else {
        for(unsigned short i=0; i<xa; i++) {
            for(unsigned short j=0; j<ya; j++) {
                if(matrixa[i][j]!=matrixb[i][j]) return 0;
            }
        }
    }
    return 1;
};
bool vertikal() {
    if(xa!=xb || ya!=yb) return 0;
    else {
        for(unsigned short i=0; i<xa; i++) {
            for(unsigned short j=0; j<ya; j++) {
                if(matrixa[i][j]!=matrixb[i][ya-1-j]) return 0;
            }
        }
    }
    return 1;
};
bool horizontal() {
    if(xa!=xb || ya!=yb) return 0;
    else {
        for(unsigned short i=0; i<xa; i++) {
            for(unsigned short j=0; j<ya; j++) {
                if(matrixa[i][j]!=matrixb[xa-1-i][j]) return 0;
            }
        }
    }
    return 1;
};
bool kananbawah() {
    if(xa!=yb || ya!=xb) return 0;
    else {
        for(unsigned short i=0; i<xa; i++) {
            for(unsigned short j=0; j<ya; j++) {
                if(matrixa[i][j]!=matrixb[j][i]) return 0;
            }
        }
    }
    return 1;
};
bool kiribawah() {
    if(xa!=yb || ya!=xb) return 0;
    else {
        for(unsigned short i=0; i<xa; i++) {
            for(unsigned short j=0; j<ya; j++) {
                if(matrixa[i][j]!=matrixb[yb-1-j][xb-1-i]) return 0;
            }
        }
    }
    return 1;    
};

int main() {
    cin>>xa>>ya;
    for(unsigned short i=0; i<xa; i++) {
        for(unsigned short j=0; j<ya; j++) {
            cin>>matrixa[i][j];
        }
    }
    cin>>xb>>yb;
    for(unsigned short i=0; i<xa; i++) {
        for(unsigned short j=0; j<ya; j++) {
            cin>>matrixb[i][j];
        }
    }
    if(identik()) cout<<"identik"<<endl;
    else if(vertikal()) cout<<"vertikal"<<endl;
    else if(horizontal()) cout<<"horisontal"<<endl;
    else if(kananbawah()) cout<<"diagonal kanan bawah"<<endl;
    else if(kiribawah()) cout<<"diagonal kiri bawah"<<endl;
    else cout<<"tidak identik"<<endl;
    return 0;
}