#include <iostream>
#include <iomanip>

struct beras {
    unsigned short w;
    unsigned short c;
    double CostPerWeight;
};

typedef beras Beras;

using std::cout;
using std::cin;
using std::endl;

Beras B[1000];
Beras BSorted[1000];

void insertionSort(unsigned short);

int main() {
    unsigned short n;
    unsigned int x;
    cin>>n>>x;
    for(unsigned short i=0; i<n;i++) {
        cin>>B[i].w;
    }
    for(unsigned short i=0; i<n;i++) {
        cin>>B[i].c;
        B[i].CostPerWeight=((double)B[i].c)/B[i].w;
        insertionSort(i);        
    }
    unsigned short i=0;
    while(x>0 && i<n) {
        if(i!=0) {
            if(BSorted[i].w < x) {
                BSorted[i].CostPerWeight=(BSorted[i].CostPerWeight*BSorted[i].w)+BSorted[i-1].CostPerWeight;
                x-=BSorted[i].w;
            } else {
                BSorted[i].CostPerWeight=(BSorted[i].CostPerWeight*x)+BSorted[i-1].CostPerWeight;
                break;
            }
        } else {
            if(BSorted[i].w < x) {
                BSorted[i].CostPerWeight=BSorted[i].CostPerWeight*BSorted[i].w;
                x-=BSorted[i].w;
            } else {
                BSorted[i].CostPerWeight=BSorted[i].CostPerWeight*x;
                break;
            }
        }
        i++;
    }
    if(i==n) i--;
    cout<<std::setprecision(5)<<std::fixed<<BSorted[i].CostPerWeight<<endl;

    return 0;
}

void insertionSort(unsigned short n) {
    unsigned short i = n;
    BSorted[n]=B[n];
    if(i!=0) {
        while(i>0 && BSorted[i-1].CostPerWeight<BSorted[i].CostPerWeight) {
            Beras tmp = BSorted[i-1];
            BSorted[i-1]=BSorted[i];
            BSorted[i]=tmp;
            i--;
        }
    }
}