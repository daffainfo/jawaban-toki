#include <bits/stdc++.h>
using namespace std;

int main() {
    short kaki[10001] = {0}, n, m, tmp, used = 0;
    cin>>n>>m;
    short *sepatu = new short[m];
    for(short i=0; i<n; i++) {
        cin>>tmp;
        kaki[tmp]++;
    }
    for(short i=0; i<m;i++)
        cin>>sepatu[i];
    sort(sepatu, sepatu + m);
    while(--m >= 0) {
        tmp = sepatu[m];
        if(kaki[tmp] > 0 || kaki[tmp - 1] > 0) {
            kaki[((kaki[tmp] > 0) ? tmp : (tmp - 1))]--;
            used++;
        }
    }
    cout<<used<<'\n';
    return 0;
}