#include <bits/stdc++.h>
#define us unsigned short

using namespace std;

typedef struct a {
    string id;
    us a, b, c;
}peserta;

void swap(peserta &a, peserta &b) {
    peserta tmp = a;
    a = b;
    b = tmp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    us t;
    cin>>t;
    for(us i=0; i<t; i++) {
        us n, m;
        cin>>n>>m;
        string search;
        cin>>search;
        peserta * olim = new peserta[n];
        for(us j=0; j<n; j++) {
            cin>>olim[j].id>>olim[j].a>>olim[j].b>>olim[j].c;
        }
        for(us j=0; j<m; j++) {
            for(us k=0; k<n; k++) {
                if(j==k) continue;
                if(olim[k].c > olim[j].c) {
                    swap(olim[k], olim[j]);
                } else if(olim[k].c == olim[j].c) {
                    if(olim[k].b > olim[j].b) {
                        swap(olim[k], olim[j]);
                    } else if(olim[k].b == olim[j].b) {
                        swap(olim[k], olim[j]);
                    }
                }
            }
        }
        bool found = false;
        for(us j=0; j<m; j++) {
            if(search==olim[j].id) {
                found = true;
                break;
            }
        }
        if(found) cout<<"YA"<<'\n';
        else cout<<"TIDAK"<<'\n';
    }
    return 0;
}