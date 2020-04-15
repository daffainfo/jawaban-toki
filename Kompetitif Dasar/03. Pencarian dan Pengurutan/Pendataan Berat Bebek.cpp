#include <iostream>

using namespace std;

unsigned n, weight[100000];
int binarysearchrange(int);

int main() {
    unsigned q, x, y;
    cin>>n;
    for(unsigned i = 0; i<n; i++) {
        cin>>weight[i];
    }
    cin>>q;
    for(unsigned i=0; i<q; i++) {
        cin>>x>>y;
        cout<<binarysearchrange(y)-binarysearchrange(x)<<endl;
    }
    return 0;
}

int binarysearchrange(int a) {
    unsigned first=0;
    int last=n-1, index=-1;
    while(first<=last && index==-1) {
        int mid=(last+first)/2;
        if(weight[mid]<=a) {
            first=mid+1;
            if(first>n-1) return first;
            if(weight[first]>a) {
                index=first;
            } 
        } else if(weight[mid]>a) {
            last=mid-1;
            if(last<0) return 0;
            if(weight[last]<a) {
                index=last+1;
            }
        }
    }
    return index;
}