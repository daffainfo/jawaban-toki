#include <bits/stdc++.h>
using namespace std;
typedef struct coklat {
    unsigned long long h, b;
    bool operator < (const coklat &a) const { return h < a.h; };
}cc;

int main() {
    cc arr[100000];
    unsigned long long d, total = 0, n;
    cin>>n>>d;
    for(int i=0; i < n; i++)
        cin>>arr[i].h>>arr[i].b;
    sort(arr, arr + n);
    for(int i=0; i < n; i++) {
        unsigned long long bought = (arr[i].b * arr[i].h <= d) ? arr[i].b : (d / arr[i].h);
        d -= (bought * arr[i].h);
        total += bought;
    }
    cout<<total<<'\n';
    return 0;
}