#include <bits/stdc++.h>
using namespace std;
typedef struct friends {
    int start, endtime;
    bool operator < (const teman &a) const { return endtime < a.endtime; };
}teman;

int main() {
    teman a[100000];
    int n, start = 0, invited = 0;
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>a[i].start>>a[i].endtime;
        a[i].endtime += a[i].start - 1;
    }
    sort(a, a + n);
    for(int i=0; i < n; i++) {
        if(a[i].start > start) {
            invited++;
            start = a[i].endtime;
        }
    }
    cout<<invited<<'\n';
    return 0;
}