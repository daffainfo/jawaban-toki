#include <iostream>

using std::cout;
using std::cin;
using std::endl;

unsigned short petak[100][100];

int main() {
    unsigned short n,m;
    unsigned int k;
    cin>>n>>m>>k;
    for(unsigned short i=0; i<n; i++) {
        for(unsigned short j=0; j<m; j++){
            cin>>petak[i][j];
        }
    }
    bool menarik=false;
    unsigned short i, j;
    for(j=0; j<m; j++) {
        for(i=0; i<n; i++){
            unsigned int kemenarikan;
            if(m==1 && n==1) {
                kemenarikan=0;
            } else if(m==1) {
                kemenarikan=((i==0) ? 0:petak[i-1][0]) * ((i==n-1) ? 0:petak[i+1][0]);
            } else if(n==1) {
                kemenarikan=((j==0) ? 0:petak[0][j-1]) * ((j==m-1) ? 0:petak[0][j+1]);
            } else if(i==0 && j==0) {
                kemenarikan=petak[1][0]*petak[0][1];
            } else if(i==n-1 && j==0) {
                kemenarikan=petak[i-1][0]*petak[i][1];
            } else if(i==0 && j==m-1) {
                kemenarikan=petak[0][j-1]*petak[1][j];
            } else if(i==n-1 && j==m-1) {
                kemenarikan=petak[i][j-1]*petak[i-1][j];
            } else if(i==0) {
                kemenarikan=petak[i][j-1]*petak[i][j+1]*petak[i+1][j];
            } else if(i==n-1) {
                kemenarikan=petak[i][j-1]*petak[i][j+1]*petak[i-1][j];
            } else if(j==0) {
                kemenarikan=petak[i-1][j]*petak[i+1][j]*petak[i][j+1];
            } else if(j==m-1) {
                kemenarikan=petak[i-1][j]*petak[i+1][j]*petak[i][j-1];
            } else {
                kemenarikan=petak[i][j-1]*petak[i][j+1]*petak[i-1][j]*petak[i+1][j];
            }
            if(kemenarikan==k) {
                menarik=true;
                break;
            }
        }
        if(menarik) break;
    }
    if(menarik) {
        cout<<i+1<<" "<<j+1<<endl;
    } else {
        cout<<"0 0"<<endl;
    }
    return 0;
}